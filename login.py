import requests
import config
from bs4 import BeautifulSoup

def can_login():
    LOGIN_URL = "https://atcoder.jp/login"
    session = requests.session()
    response = session.get(LOGIN_URL)
    soup = BeautifulSoup(response.text, "lxml")
    csrf_token = soup.find(attrs={"name": "csrf_token"}).get("value")

    login_info  = {
        "csrf_token": csrf_token,
        "username": config.USERNAME,
        "password": config.PASSWORD
    }

    result = session.post(LOGIN_URL, data=login_info)
    result.raise_for_status()
    if result.status_code==200:
        return [session, csrf_token]
    else:
        return ["", ""]

if __name__ == "__main__":
    print("")