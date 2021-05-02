import requests
import urllib.parse as urlparse


def check_web_fake(host_name):
    # connect check
    if "http" not in host_name:
        host_name = "https://" + host_name
    try:
        res = requests.get(host_name, timeout=3)
        res.raise_for_status()
    except Exception:
        return 2

    # robots.txt check
    try:
        res = requests.get(
            urlparse.urljoin(host_name, "robots.txt"),
            timeout=3,
        )
        if res.status_code != 200:
            return 1

        if "144c9defac04969c7bfad8efaa8ea194.html" not in res.text:
            return 1
    except Exception:
        return 1

    # sitemap.xml check
    try:
        res = requests.get(
            urlparse.urljoin(host_name, "sitemap.xml"),
            timeout=3,
        )
        if res.status_code != 200:
            return 1

        if "144c9defac04969c7bfad8efaa8ea194.html" not in res.text:
            return 1
    except Exception:
        return 1

    # FLAG check
    try:
        res = requests.get(
            urlparse.urljoin(host_name, "144c9defac04969c7bfad8efaa8ea194.html"),
            timeout=3,
        )
        if res.status_code != 200:
            return 1

        if "FLAG{wow_y0u_h4ve_3po4ted_th3_7ake}" in res.text:
            return 0
        else:
            return 1
    except Exception:
        return 1


if __name__ == "__main__":
    print(check_web_fake("http://localhost"))
