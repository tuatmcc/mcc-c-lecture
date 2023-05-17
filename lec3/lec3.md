# MCC C言語部内講習会 第3回

## この講座の対象の人
 - MCC部員
 - C言語を初歩から学びたい人


**この後の内容をチラ見して内容を知っていそうだと判断できる人は次回以降の参加でも大丈夫です！**


## 動的配列
今回は動的配列について学びます。その前に、配列についてちょっとだけ復習をしておこうと思います。

### 配列
配列とは、**同じ型**のデータを連続に並べたものです。
今まで学んだ配列変数の定義の仕方として、次のようなものがありました。
```c
int main() {
	int arr[3];
}
```
このように配列を定義した場合、上の例における `arr` の長さ（サイズ）は `3` で固定されており、後から伸長することは不可能です。  

### 動的メモリ確保(malloc)
後から要素数を変更できる配列を使うためには、`malloc` 関数を用いて動的にメモリを確保する必要があります。`malloc` 関数はヘッダファイル `stdlib.h` に定義されています。次に `malloc` 関数の使用例を示します。  
```c
#include <stdlib.h>

int main() {
	int *arr = (int *)malloc(sizeof(int)*3);
}
```
上の例において、`int*` 型の変数 `arr` は `3` 要素分のメモリを持っています。また、次のようにして、ユーザーの入力分だけのメモリを確保することも可能です。  
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n; // 配列の要素数
	int *arr; // 動的配列を割り当てるためのポインタ変数

	scanf("%d", &n); // ユーザーからの入力を受け取る
	arr = (int *)malloc(sizeof(int) * n);
}
```
さて、ここで `malloc` 関数について詳しく説明したいと思います。  
この関数の引数は、`size_t(unsigned int)` 型の、確保するメモリの Byte 数です。注意点として、C言語では型によってメモリのサイズが異なるため、異なる型を持つ同じ要素数の配列2つでそれぞれ占有するメモリの量が異なる、という点があります。具体例を次に示します。
```c
#include <stdlib.h>

int main() {
	int *arr = (int *)malloc(3); // int型3要素の配列を定義しようとした
	// int *arr = (int *)malloc(sizeof(int) * 3); 正しくはこう
	arr[0] = 12;
	arr[1] = 34;
	arr[2] = 56;
	// このデモでは発生しないが、意図しないメモリの値を書き換えてしまっている！
}
```
（ここでメモリのイメージ図をホワイトボードなどに描いて説明する）

次に、返り値について説明します。`malloc` の返り値は、`void *` 型の、確保されたメモリの先頭のポインタです。このポインタのアドレスを基準に、配列の内容にアクセスします。アクセスの記法は静的な配列と同様のものを用いることもできます。  

(ここでキャストについて説明する)

### 動的に確保したメモリの開放
さて、前項では述べませんでしたが、このように動的に確保したメモリ領域はプログラマがどのタイミングで解放するかの処理も記述する必要があります。解放するために、`free` 関数を使います。利用方法としては、確保したポインタを `free` 関数に渡すことで実行することができます。次に例を示します。
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
	int *arr = (int *)malloc(sizeof(int) * 3);
	arr[0] = 12;
	arr[1] = 34;
	arr[2] = 56;
	for (int i = 0; i < 3; ++i) {
		printf("%d\n", arr[i]);
	}
	free(arr);
}
```

このようにして、動的に確保したメモリ領域を解放することができます。  
注意点として、一度解放したメモリ領域をもう一度解放しようとするとエラーが発生します。
```c
#include <stdlib.h>

int main() {
	int *arr = (int *)malloc(sizeof(int) * 3);
	free(arr);
	// 実行時にエラー発生
	// free(): double free detected in tcache 2
	// Aborted
	free(arr);
}
```

また、一度解放したメモリ領域を参照しようとしてはいけません。メモリの内容が破壊される可能性があります。
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
	int *arr = (int *)malloc(sizeof(int)*3);
	arr[0] = 12;
	arr[1] = 34;
	arr[2] = 56;
	free(arr);
	// ↑で解放済みなのに↓で参照してしまった！
	printf("%d\n", arr[0]);
	// 佐藤の手元の環境では 0 が表示された
}
```

## 構造体
次に、構造体を紹介します。
構造体とは、異なる型のいくつかの情報をまとめて一つの型として管理するためのものです。例を見てみましょう。
```c
struct Point2D {
	int x, y;
};
```
上の例では、`int` 型の変数 `x`, `y` を持つ `Point2D` という構造体を定義しています。  
実際に `Point2D` 型の変数を宣言する際には次のように行います。
```c
struct Point2D {
	int x, y;
};

int main() {
	struct Point2D p;
}
```
また、`Point2D` の持つ `x`, `y` には次のようにアクセスすることができます。
```c
#include <stdio.h>

struct Point2D {
	int x, y;
};

int main() {
	struct Point2D p;
	p.x = 1;
	p.y = 2;
	printf("p.x=%d, p.y=%d\n", p.x, p.y);
}
```
（補足）構造体が持っている変数のことをメンバ変数と呼びます。  
  
構造体を型として宣言することもできます。
```c
struct Point2D {
	int x, y;
};
typedef struct Point2D P2D;
```
構造体の宣言とその構造体を型として宣言することを同時に行うこともできます。
```c
typedef struct Point3D {
	int x, y, z;
} P3D;
```
構造体のタグ名と型名に全く同じ名前を付けることもできます。
```c
typedef struct Vec2D {
	int x, y;
} Vec2D;
```
構造体が他の構造体をメンバに持つことも可能です。
```c
typedef struct Line2D {
	P2D from, to;
} Line2D;
```

構造体のポインタ変数を宣言することも可能です。  
構造体のポインタ変数からメンバ変数にアクセスする際には->演算子を使います。
```c
#include <stdio.h>

typedef struct Point2D {
	int x, y;
} Point2D;

int main() {
	Point2D p;
	Point2D *poi;
	
	p.x = 12;
	p.y = 34;

	printf("p.x=%d, p.y=%d\n", p.x, p.y);
	poi = &p;
	
	// 構造体のポインタ変数からのメンバアクセスには
	// -> 演算子を使う
	printf("poi->x=%d, poi->y=%d\n", poi->x, poi->y);
}
```

構造体のメモリを動的に確保することも可能です。
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Point2D {
	int x, y;
} Point2D;


int main() {
	Point2D *p = (Point2D *)malloc(sizeof(Point2D) * 1);
	(*p).x = 12;
	printf("%d\n", (*p).x);
	p->x = 34;
	printf("%d\n", p->x);
	free(p);
}
```