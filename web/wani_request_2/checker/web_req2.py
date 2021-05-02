# windows環境でrequestsが使えない場合↓↓
# https://github.com/psf/requests/issues/5476

import requests
import urllib.parse as urlparse


def check_web_req2(host_name):

    # connect check (main page)
    if "http" not in host_name:
        host_name = "https://" + host_name
    try:
        res = requests.get(host_name, timeout=3)
        res.raise_for_status()
    except Exception:
        return 2

    # check (main page)
    try:
        print(urlparse.urljoin(host_name, "page1"))
        res = requests.get(
            urlparse.urljoin(host_name, "page1"),
            timeout=3,
        )
        if res.status_code != 200:
            return 1
        if "We're sorry" not in res.text:
            return 1
    except Exception:
        return 1

    # check (secret page)
    try:
        res = requests.get(
            urlparse.urljoin(host_name, "page2"),
            timeout=3,
        )
        print(urlparse.urljoin(host_name, "page2"))
        if res.status_code != 200:
            return 1
        if "We're sorry" not in res.text:
            return 1
        else:
            return 0
    except Exception:
        return 1


if __name__ == "__main__":
    print(check_web_req2("localhost"))
