# test_tool

これはc++用のatcoderの自動テストツールです。

## 目次
* [できること](#section1)
* [例](#section2)
* [ご使用前に](#section3)
* [使い方](#section4)
* [コマンドライン引数](#section5)


## <div id="section1">できること</div>
1. g++(c++14)でコンパイルし実行。
2. テストケースを全て試す。
3. 自分の書いたコードの提出。


## <div id="section2">例</div>
```
~/test_tool/code/ABC/abc129
$ atcoder A

[1]
(入力)
1 3 4

(実際の出力)
4

(理想の出力)
4

---------- OK ----------

[2]
(入力)
3 2 3

(実際の出力)
5

(理想の出力)
5

---------- OK ----------

提出しますか？(y/n)
y


提出が完了しました!!!!!!!
```


## <div id="section3">ご使用前に</div>
#### gcc動作環境の構築
[こちら](https://qiita.com/fuji_20/items/ffa2a7b4d264e7a052c6)を参考にさせていただきました。<br/>
```stdc++.h```を作成しておいてください。
 

#### config.pyの作成
1. ```$ touch config.py```
2. ```$ open config.py```
3. config.py
    ```
    USERNAME = your_username
    PASSWORD = your_password
    ```

#### エイリアスを指定する
1. ```$ open ~/.bash_profile```
2. bash_profile
    ```
    alias atcoder="python ../../../test.py"
    ```
3. ```$ source ~/.bash_profile```


## <div id="section4">使い方</div>
1. __~/test_tool__ で ```$ python scraping.py``` を実行し、コンテストのトップページのURLを入力する。<br/>
    ```
    $ python scraping.py
         ___   .___________.  ______   ______    _______   _______ .______               
        /   \  |           | /      | /  __  \  |       \ |   ____||   _  \              
       /  ^  \ `---|  |----`|  ,----'|  |  |  | |  .--.  ||  |__   |  |_)  |             
      /  /_\  \    |  |     |  |     |  |  |  | |  |  |  ||   __|  |      /              
     /  _____  \   |  |     |  `----.|  `--'  | |  '--'  ||  |____ |  |\  \----.         
    /__/     \__\  |__|      \______| \______/  |_______/ |_______|| _| `._____|         
                                                                                         
                   .___________. _______     _______.___________.                        
                   |           ||   ____|   /       |           |                        
                   `---|  |----`|  |__     |   (----`---|  |----`                        
                       |  |     |   __|     \   \       |  |                             
                       |  |     |  |____.----)   |      |  |                             
                       |__|     |_______|_______/       |__|                            

     コンテストのURLを入力してください。
     url: https://atcoder.jp/contests/abc129


     少々お待ちください。

     100%|████████████████████████████████████████████████████| 11/11 [00:00<00:00, 14.15it/s]
     cd code/ABC/abc129
     問題にとりかかってください。

    ```

2. ```$ cd  code/{CONTEST_CATEGORY}/{CONTEST_NAME}```
    > ```$ cd code/ABC/abc132```
    
3. 必死こいてコードを書く。
4. ```$ atcoder {LEVEL} [-wt] [-s] [-h]```
    > ```$ atcoder A -wt```

## <div id="section5">コマンドライン引数</div>
```$ atcoder {LEVEL} [-wt] [-s] [-h]```
#### LEVEL (必須)
  問題の難易度(A, B, C, Dなど)を指定。
  
#### -wt (--without_test)
  テストケースを通さずに実行。コンパイル、実行して入力待ちの状態になる。
  
#### -s (--submit)
  テストケースを全てACした時、__-wt__ オプション時に強制的に提出する。

```
$ atcoder -h
usage: atcoder [-h] [-wt] [-s] level

atcoder用のc++のコンパイルと実行の簡略化と自動テストと提出

positional arguments:
  level                A, B, C, D, E, Fなどの問題のレベル(大文字で)

optional arguments:
  -h, --help           show this help message and exit
  -wt, --without_test  テストケースを通さず、自分で入力をする
  -s, --submit         提出の許可をいちいち取らない
```
  
  
