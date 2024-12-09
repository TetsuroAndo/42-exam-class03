## 必要なファイル

:one: ft_printf.c

## 使用可能な関数

```
malloc, free, write, va_start, va_arg, va_copy, va_end
```

## プロトタイプ

```
int ft_printf(const char *, ... )
```

## プログラムの内容

実際のprintfをモデルとした`ft_printf`という関数を作成してください。ただし、以下の変換指定子のみを実装します：

```
s (文字列)
d (10進数)
x (小文字の16進数)
```

## 出力例

```
呼び出し: ft_printf("%s\n", "toto")

出力: toto$
```

```
呼び出し: ft_printf("Magic %s is %d", "number", 42)

出力: Magic number is 42%
```

```
呼び出し: ft_printf("Hexadecimal for %d is %x\n", 42, 42)

出力: Hexadecimal for 42 is 2a$
```
