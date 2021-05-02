# windows環境でrequestsが使えない場合↓↓
# https://github.com/psf/requests/issues/5476

import requests
import urllib.parse as urlparse


def check_web_req1(host_name):
    secret_host = (
        "http://w4ni-secre7-h1mitu-pa6e.s3-website-ap-northeast-1.amazonaws.com/"
    )

    # connect check (main page)
    if "http" not in host_name:
        host_name = "https://" + host_name
    try:
        res = requests.get(host_name, timeout=3)
        res.raise_for_status()
    except Exception:
        return 2

    # connect check (secret page)
    try:
        res = requests.get(secret_host, timeout=3)
        res.raise_for_status()
    except Exception:
        return 2

    # check (main page)
    try:
        res = requests.get(host_name, timeout=3)
        if res.status_code != 200:
            return 1
        if "URLを入力してください" not in res.text:
            return 1
    except Exception:
        return 1

    # check (secret page)
    try:
        res = requests.get(secret_host, timeout=3)
        if res.status_code != 200:
            return 1
        if "FLAG{h77p_r3f3r3r_15_54f3_42a2cc2f275}" not in res.text:
            return 1
        else:
            return 0
    except Exception:
        return 1


if __name__ == "__main__":
    print(check_web_req1("localhost"))
