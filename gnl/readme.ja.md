## 必要なファイル

:one: get_next_line.c

:two: get_next_line.h

## 使用可能な関数

```
read, free, malloc
```

## プロトタイプ

```
char	  *get_next_line(int fd);
```

## プログラムの内容

> 行について

- 関数は、パラメータとして渡されたファイルディスクリプタから読み取った行を返す必要があります。

- "読み取られた行"とは、'\n'（ASCIIコード0x0a）またはファイル終端（EOF）で終わる0からnまでの文字の連続を指します。

- 読み取られた行の末尾に'\n'がある場合は、その'\n'を含めて返す必要があります。

> バッファについて

- EOFに到達した場合、現在のバッファをchar *に格納して返す必要があります。

> NULLについて

- バッファが空の場合はNULLを返す必要があります。
- エラーの場合はNULLを返します。
- NULL以外を返す場合、そのポインタはfree可能である必要があります。

> メモリについて

- プログラムは-D BUFFER_SIZE=xxフラグ付きでコンパイルされ、この値を関数内のread呼び出しのバッファサイズとして使用する必要があります。
- 関数はメモリリークがないようにする必要があります。
- EOFに到達した場合、返される行を除いて、mallocで確保されたメモリは0である必要があります。

> 関数について

- get_next_line関数をループで呼び出すことで、テキストやその行の大きさに関係なく、ファイルディスクリプタから利用可能なテキストを1行ずつ最後まで読み取ることができます。
- ファイル、標準出力、リダイレクションなどからの読み取りが適切に動作することを確認してください。
- get_next_lineの2回の呼び出しの間に、ファイルディスクリプタに対して他の関数呼び出しは行われません。

> ファイルについて

- バイナリファイルからの読み取り時のget_next_lineの動作は未定義とみなします。