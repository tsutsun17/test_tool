import os
import re
import subprocess
import requests
from bs4 import BeautifulSoup
from login import can_login

BASE_CODE = "#include <bits/stdc++.h>\nusing namespace std;\ntypedef long long ll;\n\nint main() {\n    \n    return 0;\n}"
CATEGORY = ["ABC", "ARC", "AGC", "Others"]

def main():
    print("\n")
    print("----------------------------------")
    print("|    atcoderの準備を開始します。  |")
    print("---------------------------------- \n")
    print("コンテストのURLを入力してください。")
    print("url: ", end="")
    BASE_URL = input() + "/tasks"
    print("\n")

    session, _ = can_login()
    if not session:
        print("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^")
        return print("ログインに失敗しました。")
    else:
        print("少々お待ちください。\n")
        if get_testcases(BASE_URL, session):
            return print("問題にとりかかってください。\n")
        else:
            print("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^")
            return print("エラーが発生しました。")

# カテゴリ分け
def get_category(contest_name):
    top = contest_name[:3]
    if top=="abc":
        return 0
    elif top=="arc":
        return 1
    elif top=="agc":
        return 2
    else:
        return 3

# テストケースの取得
def get_testcases(base_url, session):
    try:
        contest_name = base_url.split("/")[4]
        contest_category_no = get_category(contest_name)
        category = CATEGORY[contest_category_no]

        response = session.get(base_url)
        soup = BeautifulSoup(response.text, "lxml")
        tbody = soup.find_all("tr")
        problem_links = []
        for td in tbody:
            tsoup = BeautifulSoup(str(td), "lxml")
            if tsoup.find("td"):
                a_tag = tsoup.find("a")
                problem_links.append(a_tag)

        # ファイルの作成
        for link in problem_links:
            name = link.text

            # テスト用のin,outのディレクトリを作成
            os.makedirs('./code/{0}/{1}/test/{2}/in'.format(category, contest_name, name))
            os.makedirs('./code/{0}/{1}/test/{2}/out'.format(category, contest_name, name))

            # 問題ごとにファイルを作成
            with open('./code/{0}/{1}/{2}.cpp'.format(category, contest_name, name), 'w') as f:
                f.write(BASE_CODE)

        for link in problem_links:
            name = link.text
            link = link.get("href")
            
            response = session.get("https://atcoder.jp" + link)
            soup = BeautifulSoup(response.text, "lxml")
            lang_ja = soup.find("span", class_="lang-ja")
            lang_ja_soup = BeautifulSoup(str(lang_ja), "lxml")
            pre = lang_ja_soup.find_all('pre')[1:]
            sample_in = list(pre[0::2])
            sample_out = list(pre[1::2])

            for index, sample in enumerate(sample_in):
                with open('./code/{0}/{1}/test/{2}/in/{3}.txt'.format(category, contest_name, name, index+1), 'w') as f:
                    f.write(sample.text)

            for index, sample in enumerate(sample_out):
                with open('./code/{0}/{1}/test/{2}/out/{3}.txt'.format(category, contest_name, name, index+1), 'w') as f:
                    f.write(sample.text)

        print('cd code/{0}/{1}'.format(category, contest_name))
        return True
    except Exception as e:
        print(e)
        return False

if __name__ == "__main__":
    main()