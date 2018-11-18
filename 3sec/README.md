### 3-1 SLList において、push(x)、pop()、add(x)、remove() の特殊なケースすべて をダミーノードを使って避けられないのはなぜか。
pop：最後の要素を削除する場合は特別で、tailをNULLに設定する。

→要素数が0の時にdummyのtailにnullを設定する必要がある。
add：n=0の場合は特別でtail=head=nullとする。この場合、tailもheadもuになる。
→n=0の場合、dummyのtailとheadにnullを入れる必要がある。
remove：n=0の場合は特別でtail=head=nullとする。この場合、tailもheadもuになる。
→addと同じ

### 3-2 SLListのメソッドsecondLast()を設計、実装せよ。これはSLListの末尾の 1 つ前の要素を返すメソッドである。リストの要素数 n を使わずに実装してみよ。
headから要素を辿り、current->next == tailになるまで探索し続ける。
### 3-3 SLListのget(i)、set(i,x)、add(i,x)、remove(i)を実装せよ。いずれの操 作の実行時間もO(1+i)であること。
SLListに実装。
### 3-4 SLListのreverse()操作を設計、実装せよ。これはSLListの要素の順番を逆 にする操作である。この操作の実行時間は O(n) でなければならず、再帰を使ってはならな い。また、他のデータ構造を補助的に使ったり、新しいノードを作ったりしてもいけない。
### 3-5
### 3-6
### 3-7
### 3-8
### 3-9
### 3-10
### 3-11

