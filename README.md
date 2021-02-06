# 数据结构与算法笔记

#### 基本概念
##### 什么是数据?
数据是计算机加工处理的原料
##### 数据元素
一个有意义的个体,由一系列数据构成,通过这个数据完整描述一个个体
##### 数据对象
数据元素的集合,例如一群人就是一个数据对象,这个对象中有一个个的人,这些个体作为数据元素组成一个数据对象
##### 数据类型
由两部分组成
1. 数据内容本身
2. 对数据所进行的操作
> 数据类型是数据对象以及对其进行的一系列操作组成的,即便是数据相同,但是所做的操作不同,数据类型也不一样
##### 数据结构三要素
1. 逻辑结构
    描述数据元素之间的关系
2. 存储结构
    使用实际的编程语言实现所描述的逻辑结构
3. 运算方式(同样包括设计与实现)

### 线性表
#### 特征
1. 有序的序列
2. 一对一的关系
3. 数据元素是有限的
> 没有数据元素的线性表是空表
#### 概念
* 线性表数据元素是一个集合,集合元素拥有相同的类型
* 集合中前一个元素称之为前驱,当前元素后一个元素称之为后继
* 显而易见的,第一个元素没有前驱,最后一个元素没有后继
* 数据元素之间是一一对应的关系
* 存储地址连续

### 单链表

一个节点只包含下一个节点的指针
链表从头指针开始一直指向下一个节点,最后一个节点指向NULL,即空指针

> 链表的结点由**数据域**和**指针域**构成
> * 我们在定义链表时,会习惯性的定义一个头节点,以便统一链表节点的插入和删除操
> * **头节点** 也称之为**首元**节点,最后一个节点称之为**尾元**节点
> * 一般,链表实际从指数1开始算起
>

链表同样包括初始化,插入,删除,获取指定元素等操作

#### 顺序表与单链表的对比

| 数据结构 | 顺序表 | 单链表 |
|---|---|---|
| 存储结构 | 使用连续的内存空间进行存储 | 采用链式结构,使用任意存储单元存储线性表元素 |
| 时间性能 | 查找| 直接通过索引查找,效率较高 | 需要从头遍历单向链表,较慢|
|| 插入和删除| 需要频繁移动数组元素的位置,效率较低 | 通过链表指针进行增删,效率较高 |
| 空间性能 | 需要预先规划空间,大了浪费,小了不够用 | 可以灵活使用内存空间,按需使用,元素个数不受限制 |

### 循环链表(单向)
循环链表与单向链表的主要区别在于其最后一个节点是指向第一个节点的, 这样形成了一个闭圈,同时在对循环链表进行增删查的时候,需要注意对第一个节点进行特殊处理,因为第一个节点有两个指针指向该节点,同时由于其闭圈的特性,在遍历的时候可以采用`while`循环

### 双向链表
双向链表包括一个数据域和两个指针域,分别指向前驱和后继

#### 几种链表的比较
| 链表结构 | 优点 | 缺点 |
|---|---|---|
| 单链表 | 在找出结点之后,插入和删除的开销较低,不需要预分配空间 | 查找速度慢 |
| 循环链表 | 改进的闭环链表,可以从任意位置遍历链表 | 没有解决查找速度慢的问题 |
| 双向链表 | 优化查找速度,可以反向遍历,平均查找速度提高了一倍 | 需要记录前缀节点,增加了程序复杂度,占用了更多空间 |
| 静态链表 | 再插入和删除元素时,只移动游标,改进了顺序表在增删时需要移动元素的缺点 | 1. 没有解决顺序表长度固定的问题<br>2. 失去了顺序表随机存储的特性 |

### 静态链表
静态链表实际上是使用数组来模拟链表的特征,从而兼具两者的优点的一种数据结构.

具体而言就是:
1. 初始化一个足够大小的结构数组,其中结构主要由三部分组成:
    * 数组下标
    * 实际数据
    * 游标(相当于链表指向下一节点的指针)
2. 这个结构数组的第一个和最后一个元素用来存储静态链表的信息,不存储实际数据:
    * 第一个数组元素游标表示的是数组中第一个空置位的下标,初始为1
    * 最后一个数组元素的游标表示数组中第一个插入元素的下标,若静态数组为空,则游标值为0,这样一来,最后一个元素就可以看作是**静态链表数据域的头节点**
3. 静态链表中未使用的元素组成一个备用链表,这是一个抽象出来的链表,如前所述,可以把数组第一个元素视为**备用链表的头节点**
4. 静态链表中,存储数据的最后一个元素的游标为0,表示其作为实际存储数据的最后一个节点,这一点和最后一个数组元素游标为0的概念是不一样的.

> 数据域链表中游标为0表示该元素是数据域最后一个节点
> 数组中最后一个元素游标为0表示该静态链表实际长度为0,即没有插入过数据

#### 静态链表的删除操作
主要分三步:
1. 通过数据域头节点(最后节点的游标)进行遍历,找到待删除节点的前一个节点
2. 将前节点的游标设置为待删除节点的游标,则待删除游标此时被排除在数据与之外
3. 通过待删除节点的下标:
      * 将备用链表的头节点游标赋值给待删除节点的游标
      * 将备用链表头节点游标设置为待删除节点下标

    经以上步骤,则待删除节点被设置为备用链表第一个节点,**该方式并没有真正释放待删除节点中存放的数据(*链表中数据并不是使用malloc分配的内存*),这些数据会在之后的插入节点时被覆盖**

### 栈和队列
栈是仅允许在表尾增加和删除的一种线性表

>允许插入和删除的一端称之为**栈顶**,另一端称之为**栈底**
> 不含任何元素的栈称之为空栈


#### 栈与链栈

栈就是一个后进先出的线性表,单数使用线性表的缺点在于,栈的大小是事先设置的,无法灵活改变大小,为了改变这个状况,使用**链栈**这种使用链表来实现栈的数据结构,这与使用线性表实现栈最大的区别在于:
* 每次加入栈需要使用malloc分配空间
* 链栈是根据实际大小加入或者弹出栈元素,空间使用灵活
* 使用指针而不是数组下标维护栈元素

#### 队列

队列是一种从头部删除,尾部加入的线性表,这种增删结构导致一个现象:**假溢出**:

> 假溢出是指使用线性表实现队列的时候,虽然数组中还有空间,但是队列尾部已经到达数组边界,由于数据只能从尾部加入,所以此时无法再添加元素
> (产生假溢出是因为队列头部在删除元素的时候会向数组中部移动,导致队列头出现空隙)  

为了解决"假溢出"的问题,我们使用循环队列这个抽象出来的概念,即将队列想象成一个头尾相接的圆圈,这个队列能容纳的元素数量为MAX_SIZE,首部下标为front,尾部下标为rear

1. 初始化队列时,我们将tear和front置为0
2. 每当队列加入元素,则尾下标变为`(rear + 1) % MAX_SIZE`
3. 每当队列减少,则头下标变为`(front + 1) % MAX_SIZE`

> 两者增加的值都是当前值加1再模MAX_SIZE,这里取模的原因就是让首尾下标都不会越界,形成一种环状的错觉

![](mdPic/recycleQueue.png)

由于首尾下标都是以一种循环的方式赋值,所以不会出现"假溢出"的情况
同时,判断循环队列为空,只需判断`rear == front`即可
判断循环队列已满,只需判断`(rear + 1) % MAX_SIZE == front`即可(实际上就是尾下标位于头下标前面)

> * 如果循环队列首尾下标初始化为0,那么每次尾部增加之后下标位置实际上是一个空位,这个空位实际上被浪费了,一直都没有使用
> * 又或者可以将首尾下标都初始化为-1,这时就不会浪费空间了,但是在增加第一个元素的时候,需要做特殊处理,反而更麻烦,而且-1这个下标是不直观的,索性就浪费一个空间,降低代码的复杂度
> * 循环队列的实际存储的最大数据值为`MAX_SIZE - 1`


**注意: 循环队列的头下标不一定会小于尾下标**,这是因为在动态增删的情况下,尾下标很可能会越过数组最大下标

#### 字符串

##### BF算法

BF算法全称为Brute-Force算法,是对字符串进行操作的一个暴力直观的算法

1. 假设主字符串的下标用i表示,待查找的字符串(子串)下标使用j表示,假设主串长度为mLength,子串长度为cLength
2. 将子字符串中的字符与主字符串中的字符逐一比较,每当字符相等,则i和j都递增加1
3. 当碰到不相等字符时,说明主字符串与子字符串相比较的这段字符起点需要向后移动一格
4. 也就是说这时候i需要"回溯",这里的回溯包含两步:
    * 回到开始比较的起点
    * 前进一格,再次开始比较字符
5. 那么如何确定i回溯的位置呢?这时候就可以把子串的下标作为参考了,因为在不断地比较推进过程中,主串的比较起点会不断变化,唯一不变的是,主串和子串所增加的步数是一致的,如果此时`i - j`就得到主串本次开始比较的起点,那么既然此时有一个字符不同,主串自然就应该设置一个新的比较起点,这个新起点刚好是旧起点的后一个,即`i - j + 1`;

> 总的来说,BF算法也是不断地遍历主串,和子串进行比较最终得出子串在主串中的位置,或者子串根本不在主串中,此时我们返回一个不可能的下标:-1

这里需要注意的是如果主串下一个开始的起点即`i - j + 1`再加上子串长度减1,得到的值(`i - j + cLength`)已经超过了主串最大下标(`mLength - 1`),则说明主串不包含这个子串了,使用程序表示即:
```
if (i - j + cLength > mLength - 1) {
    return -1;      // 不包含子串返回-1
}
```
##### KMP算法

需要提前知悉的基本概念:

1. **前缀**与**后缀**:这是针对一个字符串而言的,比如`abc`这个字符串,前缀即是不包含最后一个字符的所有连续的子串,即`a, ab`这三个子串,同理,后缀即是`c, bc`这三个子串

2. KMP算法的一个启示性思想是:作为一个人来说,肯定不会像BF算法那样无脑回溯主串的下标或者说指针,当人脑去匹配两个字符串时,主要有两个步骤:
    1) 依次对比两个字符串的字符
    2) 发现有一个字符不同,此时我们头脑中已经存在一个很重要的信息:**我们知道在此之前的字符都是匹配的**,那么根据这个信息,我们在考虑下一次进行匹配的起点,从这个起点开始比较

举例子来说,对于如下两个字符串:
```
str1 = "abc abcd abcde"     // 这个字符串称之为主串,就是被查找的字符串
str2 = "abcd"   // 这个字符串一般称之为模式,类似于查找时使用正则表达式,即需要匹配的字符串
```
我们在比较到第四个字符`d`的时候,发现和空格不匹配,此时我们肯定不会傻傻地从主串的第二个字符开始比较,而是将模式串直接放到空格之后的`abcd`开始比较
那么以上这个过程是如何产生的呢?KMP算法就是将这个思想进行实现的一个算法
为了理解这个过程,有几点隐含在以上人脑的思维过程中:
1. 我们会在脑海中将模式字符串移动到主串下面进行比较,不论匹配与否,主串根本没有移动,也就是说这里主串下标在比较的时候不存在"回溯",也就是说不存在BF算法中减少主串比较下标的做法
2. 之前已经被匹配的部分字符,不用再重复比较了,这意味着我们的比较,将从**未被匹配**的字符开始,这也是从另一个角度解释主串下标不回溯的问题
3. 

我们要回答一个简单的问题:

给你一个字符串str,使用这个字符串作为模式,去随便找一个字符串进行匹配,如果这个字符串str在比对到第j个字符时,与主串不同,那么我们接下来应该从str的哪个地方开始与主串进行比较呢?
* 这里就要引入前缀和后缀的概念了,**已经匹配的字符**是一个很重要的线索,举个例子:
```
str1 = "ababbcde"
str2 = "ababf"
```
* 这两个字符串在第5个字符处不相同,那么匹配的**前四个字符**有什么特点?
我们发现有规律的重复,这种重复在暗示我们的大脑,我们应当把`str2`向右移动到**下一个最大长度匹配的字符中**,也就是说我们应该实现这样的移动以进行下一次比较:
```
ababbcde
  ababf
```
* 凭什么这样移动?  
因为我们知道,我们最终的目的是匹配一整个模式字符串(如果主字符串真的包含模式的话),如果前一次的匹配没有获得成功,我们在下一次移动模式字符串进行匹配的时候,**应该尽可能地匹配相同的字符**
* 问题来了,怎样移动能尽可能多地匹配字符?  
**找规律**,这个规律就隐藏在已经匹配的那些字符中,我们将已经匹配的字符单独拎出来看,比如上面例子中的`abab`,由于最后一个字符`f`没有匹配上,我们必须要移动模式字符串进行下一次比对了,如何根据这个已经匹配的字符串进行移动,就是决定算法效率的关键

我们已经知道一个字符串的前缀与后缀了,那么引入这个概念的目的是什么呢?
让我们使用前缀和后缀来处理`abab`这个字符串:
* 从开头来看,这个字符串的前缀有如下这些:`a, ab, aba`,相应的其后缀为:`b, ab, bab`,很明显的前缀和后缀相同的字符串是`ab`,我们还可以进一步地说,这是一个最长相等的前后缀,找到了这个最大值(此处长度为2),我们就可以很"安全"的跳过一个最大相同前后缀字符的长度,或者说经过这样的移动,我们**尽可能地保证了模式字符串与主字符串有尽可能多地字符匹配**

##### 如何使用程序代码实现计算每一个字符在不匹配的时候,模式字符串应该移动的距离?
如下表所示,index代表字符串数组的下标,pattern即为字符串数组,next就是子字符串的最大相等前后缀的长度


| index  | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---| --- | ---|---|---|---|---|---|
| pattern | a | b | a | b | c | a | a | c |
| next | 0 | 0 | 1 | 2 | 0 | 1 | 1 | 0 |

接下来就开始计算next这一行是如何计算出来的
首先列出这个pattern字符串的所有前缀以及其本身:

| index | 字符串长 | 前缀字符串 | 最大相等前后缀长度(next) |
|:---:|:---:|---|:---:|
| 0 | 1 | a | 0 |  
| 1 | 2 | ab | 0 |  
| 2 | 3 | <span class="underline">a</span>ba | 1 | 
| 3 | 4 | <span class="underline">ab</span>ab | 2 |   
| 4 | 5 | ababc | 0 |
| 5 | 6 | <span class="underline">a</span>babca | 1 |
| 6 | 7 | <span class="underline">a</span>babcaa | 1 |
| 7 | 8 | ababcaac | 0 |

上表以字符串长度递增的方式展示,就是为了说明长度在增加之后,最大相等前后缀的长度是如何根据其前一个字符串的最大相等前后缀长度进行推导的,推导过程如下

1. 根据上表,我们可以从只有一个字符的字符串开始推导,当只有一个字符时,不存在前后缀字符串,我们暂时认为对应**最大相等前后缀**长度(后文简称为最大长度)为0;  
2. 在求第二个长度时,将第二个字符和第一个字符相比,如果相等,那么说明最大长度就是1  
3. 第三个字符串,很容易看出最大前后缀就是`a`,长度就是1  
4. 第四步重点来了,我们**已知前一个字符串的最大相等前后缀长度**,这里是1,新加入的字符顶多使得这个长度再加一,那么怎么比较呢?新加入的这个字符是`b`,前一个最大相等前后缀是`a`,紧接着的是字符`b`,如果新加入的字符刚好等于`b`,那么在此基础上,新形成的字符串就是前一个最大相等前后缀长度加1  
5. 如果我们设前一个字符串的最大相等前后缀长度为`k`,当前字符串为`curString`,当前字符串长度为`curLen`因为长度总是比下标多1,很容易得出`curString[k]`就是前一个字符最大相等前后缀后面一个字符(即第4步中的字符`b`),我们将这个字符和当前字符串最后一个字符进行比较,即`curString[k] == curString[curLen - 1]`,如果相等,那么就说明当前字符串最大相等前后缀长度为`k + 1`;那么,**如果不相等呢?**  
6. 不相等说明什么问题?不相等说明新加入的这个字符不能和前一个字符串的最大相等前缀组成一个新的最大相等前缀,既然最大没戏了,那就退而求其次,我能不能求第二大的?当然可以,那么第二大的相等前缀怎么得来的?这里就类似`递归`了;  
**前一个字符串的第二大相等前后缀**不就是**前一个字符串的前一个字符串的最大相等前后缀**吗?  
7. 来看第五个字符前缀作为例子,新加入的这个字符是`c`,那么`curString[2]`就等于`b`,这里就碰到了不相等的情况,我们顺着表格往上看,可知,这个**第二大相等前后缀**长度是1,也就是说k变成了1,此时`curLen`为5,套用第5步的比对方式即是:`curString[1] == curString[5 - 1]`,即是`b == c`,这里又不相等了,同样的逻辑,我们可以把`k`回溯到`0`,这里`c`和`a`也不相等,此时已经到头了,说明第五个字符串最大相等前后缀长度就是`0`  
8. 依据这个逻辑,我们填完了最后一列的数值,在算法表示中,这一列会被表示为一个数组,这个数组名通常命名为`next`  
8. 把上面的步骤使用代码描述出来,我们来生成一个next数组
```c
void generateNext (char * str, int length, int * next) {
    int i = 1;
    int k = 0;  
    next[0] = 0; // 一个字符的字符串,最大相等前后缀长度为0
    while (i < length) {
        if (str[i] == str[k]) {
            k++;
            next[i] = k;
            i++;
        } else {
            if (k == 0) {
                i++;
            } else {
                k = next[k - 1];
            }
        }
    }
}
```
测试代码如下:
```c
int main () {
    char * str = "ababcaac";
    int * next = malloc(strlen(str) * sizeof(int));
    generateNext(str, strlen(str), next);
    for (int i = 0; i < strlen(str); i++) {
        printf("%d\t", next[i]);
    }
}
```
打印出的结果是:
`0  0   1   2   0   1   1    0`  
一般情况下,为了方便之后进行字符串对比算法,我们会将这个数组的结果右移一位,数组第一位设置为-1,表示单个字符不存在前后缀  

接下来就是使用这个next数组进行字符串对比
```c
void next_to_right (int * next, int length) {
    int i = length - 1;
    for (;i > 0; i--) {
        next[i] = next[i - 1];
    }
    next[0] = -1;
}

int kmp_compare (char * str, char * pattern, int * next) {
    int strLen = strlen(str);
    int patLen = strlen(pattern);
    next_to_right(next); // 将next数组向右移动一位,第一位赋值为-1
    int i = 0;
    int k = 0;
    while (i < strLen) {
        if (k == patLen - 1 && str[i] == pattern[k]) {
            return i - k;
            // 如果需要查找所有子串,此时可以返回一个整型数组,将第一次到最后一次找到的字串位置
            // 存入数组中,而且每找到一次,也要将k回溯一次,即:
            // k = next[k];
        }
        if (k == -1 || str[i] == pattern[k]) {
            i++;
            k++;
        } else {
            k = next[k];
        }
    }
    return -1;  // 没有找到,返回-1
}
```

> 总结KMP算法,其核心就是如何得到并利用这个next数组,正是有了这个数组,我们不必每次比对字符串都很无知地将比对位置向后移动一位,我们使用多余的空间来存储这个数组,也避免了两次循环对比造成的时间复杂度倍增

#### 树和二叉树

##### 树是N个节点的有限集,如果没有节点就称之为空树
对于非空树:
1. 有且仅有一个,称之为根节点
2. 除了根节点之外的其余节点可分为m个互不相交的有限集T1,T2...,Tm,集中每一个集合本身又是一棵树,并且称之为根的子树(SubTree)

**度**: 某个节点子节点的个数  
**节点的层**: 从根节点到目前节点经历的节点数,根节点为第一层  
**整个树的度**: 所有节点中,最大的度是整个树的度  
**树的深度**: 所有节点里,最大的层数  


#### 二叉树
1. 二叉树是一个有序树
2. 二叉树的一个节点最多只有两个子树

**为何要重点研究二叉树?**
1. 二叉树结构性最强
2. 所有的树都可以转化成二叉树
3. 不转化成二叉树,在计算机中很难处理

#### 二叉树的性质

二叉树的第i层最多有

满二叉树和完全二叉树的特点:  
* 简单来说,完全二叉树就是一个没有缺失中间结点的二叉树;  
* 或者说,如果将一个满二叉树从上至下从左至右进行连续编号,将这些编号映射到一个同样深度的二叉树中,映射完成后,如果在这个二叉树中,编号是连续的,那么这个二叉树就是完全二叉树;  

1. 叶节点只能出现在最后两层  
2. 最下层叶节点只集中在左部连续位置
3. 倒数第二层若有叶节点,一定都在右部连续位置
4. 如果一个节点的度是1,那么这个节点一定只有左孩子
5. 同样节点的二叉树,**完全二叉树的深度最小**
6. 在二叉树的第$i$层上至多有$2^{i - 1}$个节点
7. 深度为i的二叉树最多有$2^i - 1$个节点
8. 对于任何一颗二叉树,如果度2的节点数有$n_2$个,则叶子节点数(度为0)$n_0$一定有$n_2 + 1$个($n_0= n_2 + 1$)  
    > 解释: 假设一个完全二叉树,度从0到2的节点数分别为$n_0,n_1,n_2$,那么总结点数为$n = n_1 + n_2 + n_3$,再假设总分支数为$B$,因为有根节点的存在总分支和总节点数的关系是这样的:$n = B + 1$,而总分支数使用节点表示为$B = n_1 + 2 \times n_2$, 通过这三个公式可以推断出:$n_0 = n_2 + 1$
9. 具有$n$个节点的完全二叉树深度一定是$[log_2n] + 1$(这里$log_2n$向下取整)
    > 解释:假设二叉树的深度为$k$,那么完全二叉树的节点最多有$2^k - 1$个,最少有$2^{k - 1} -1$个(即上一层的总结点数)以上,用公式表示为:
    $$2^{k - 1} - 1 < n \leq 2^k - 1$$
    > 因为,$n$是一个整数(两边同时加上1),所以上式可以表示为:
    $$2^{k - 1} \le n < 2^k$$
    > 从而得出$k$的表示范围为:
    $$log_2n < k \leq log_2n + 1$$
    > 这里上下限差值为1,故得出以上结论

10. 对于完全二叉树,若从上至下,从左至右,则编号为$i$的节点,其左孩子的编号一定是$2i$, 其右孩子的编号一定是$2i + 1$;其双亲的编号一定是$i/2$

**二叉树的遍历：**
1. 前序遍历（根结点->左节点->右节点）
2. 中序遍历（左节点->根结点->右节点）
3. 后序遍历（左节点->右节点->根结点）

以上的遍历方式的称呼来源于在代码中遍历节点的时候，首先处理哪一个节点，因为节点可以使用递归遍历也可以借助于栈这种数据结构进行遍历，不管哪种方式，遍历时候都是以根结点的处理顺序作为命名的规则。

同时注意，使用栈结构进行遍历效率会稍微高一些，但是实现相对于递归更为复杂，其中的要点在于：**入栈顺序与遍历顺序相反，遇到空节点便出栈并从当前节点的右子树开始继续遍历，直到空栈或者遍历节点为空**

































<style>
    .underline {
        text-decoration: underline;
        color: red;
    }
</style>
