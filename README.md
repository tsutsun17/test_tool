# test_tool

これはc++用のatcoderの自動テストツールです。

## できること
1. g++でコンパイルし実行。
2. テストケースを全て試す。
3. 自分の書いたコードの提出。


## 例


## ご使用前に
#### gcc動作環境の構築


#### config.pyの作成
1. ```$ touch config.py```
2. config.py
    ```
    USERNAME = your_username,
    PASSWORD = your_password
    ```

#### エイリアスを指定する
1. ```$ open ~/.bash_profile```
2. bash_profile
    ```
    alias atcoder="python ../../../test.py"
    ```
3. ```$ source ~/.bash_profile```


## 使い方
1. __~/test_tool__ で ```$ python scraping.py``` を実行し、コンテストのトップページのURLを入力する。<br/>
ここで画像を追加

2. ```$ cd  code/{CONTEST_CATEGORY}/{CONTEST_NAME}```
    > ```$ cd code/ABC/abc132```
    
3. 必死こいてコードを書く。
4. ```$ atcoder {LEVEL} [-wt] [-s] [-h]```
    > ```$ atcoder A -wt```

## コマンドライン引数
```$ atcoder {LEVEL} [-wt] [-s] [-h]```
#### LEVEL (必須)
  問題の難易度(A, B, C, Dなど)を指定。
  
#### -wt (--without_test)
  テストケースを通さずに実行。コンパイル、実行して入力待ちの状態になる。
  
#### -s (--submit)
  テストケースを全てACした時、__-wt__ オプション時に強制的に提出する。
  
  
