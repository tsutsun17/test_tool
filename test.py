import os
import subprocess
import requests
import argparse

from login import can_login

# 引数: python test.py AとかBとか[大文字で] 
# - --help
# - 何もなしだったら、コンパイルして実行　かつ　テストケースを通す (全てACだったら、提出するかをy/nで尋ねる)
# - -wt : コンパイルして実行のみ (提出するかをy/nで尋ねる)
# - -s : 提出するかの確認を省略

BASE_URL="https://atcoder.jp/contests/"

def main():
    pwd = os.getcwd()
    category, contest_name = pwd.split("/")[-2:]
    can_submit = False

    parser = argparse.ArgumentParser(description='atcoder用のc++のコンパイルと実行の簡略化と自動テストと提出', prog="atcoder")

    parser.add_argument("level", help="A, B, C, D, E, Fなどの問題のレベル(大文字で)")
    parser.add_argument("-wt", "--without_test", help="テストケースを通さず、自分で入力をする", action="store_true")
    parser.add_argument("-s", "--submit", help="提出の許可をいちいち取らない", action="store_true")

    args = parser.parse_args()

    # 引数たち
    level = args.level
    wt = args.without_test
    submit = args.submit

    # コンパイル
    subprocess.call(["g++", "-o", level, '{0}.cpp'.format(level)])

    # 自動テスト or 手動テスト
    if wt:
        print("(入力)")
        ret = subprocess.check_output(['./{0}'.format(level)])
        ret = ret.decode('utf-8')
        print(ret)
        can_submit = True
    else:
        can_submit = test_result(level)

    # 提出するかどうか
    if not can_submit:
        print("\n\n")
        print("----- 処理を終了します -----")
        return ""
    if not submit:
        do_submit = submit_ques()
        if not do_submit:
            print("----- 提出はしません。 -----")
            print("----- 処理を終了します。 -----")
            return ""

    print("\n\n")
    code_submit(level, contest_name)
    return ""

# 提出するかどうかの質問
def submit_ques():
    for i in range(3):
        print("\n\n")
        print("提出しますか？(y/n)")
        do_submit = input()
        if do_submit == "y":
            return True
        elif do_submit == "n":
            return False
        else:
            if i < 2:
                print("----- yかnを入力してください -----")
    return False

# 自動テスト処理
def test_result(level):
    try:
        test_path = './test/{0}'.format(level)
        file_number = len(os.listdir(test_path + "/in"))
        ac_count = 0

        for i in range(1, file_number+1):
            with open(test_path + '/in/{0}.txt'.format(i), "r") as f_in, open(test_path + '/out/{0}.txt'.format(i), "r") as f_out:
                # コードの実行
                ret = subprocess.check_output(['./{0}'.format(level)], stdin=f_in)
                ret = ret.decode('utf-8')

                # subprocessでf_inを読み込んでからread()をする
                s_in = f_in.read()
                print('[{0}]'.format(i))
                print("(入力)")
                print(s_in)

                print("(実際の出力)")
                print(ret)

                s_out = f_out.read()
                print("(理想の出力)")
                print(s_out)

                if ret == s_out:
                    print("---------- OK ----------")
                    ac_count += 1
                else:
                    print("^^^^^^^^^^ NG ^^^^^^^^^^")
        if ac_count == file_number:
            return True
        else:
            return False
    except Exception as e:
        print(e)
        return False

# コードの提出処理
def code_submit(level, contest_name):
    session, csrf_token = can_login()
    if not session:
        print("------  ログインに失敗しました。   ------")
        return print("------  速やかに処理を終了します。 ------")
    else:
        url = BASE_URL + '{0}/submit'.format(contest_name)
        task_name = '{0}_{1}'.format(contest_name, level.lower())

        with open('{0}.cpp'.format(level), "r") as f:
            source_code = f.read()

            submit_info = {
                "data.TaskScreenName": task_name,
                "data.LanguageId": 3003,
                "sourceCode": source_code,
                "csrf_token": csrf_token
            }
            result = session.post(url, data=submit_info)
            result.raise_for_status()

            if result.status_code == 200:
                print("----- 提出が完了しました!!!!!!!!!!!!!　-----")
                print("----- 速やかに処理を終了します。 -----")
            else:
                print("----- 提出に失敗しました。。。 -----")
                print("----- 速やかに処理を終了します。 -----")

        return ""

if __name__ == "__main__":
    main()