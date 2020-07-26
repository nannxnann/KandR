# Chap 4 - Functions and Program Strucutre

? on last paragraph.
extern object can have only one definition.

## 4.1 Basics of Functions
    dummy() {} //為no-op function 常被用來預備給未開發的function
    當return type為空時預設回傳int type資料
    即便回傳型態不為void 依然可以不回傳資料 只是資料會是垃圾數值

## 4.2 Functions Returning Non-integer
    calling routine必須明確宣告使用的function 所return 之type
    如果沒有宣告且該function 與 calling routine編寫在相同文件.c內 則compile會不給過
    反之如果編寫在相異的兩份.c檔，compile會給過，但是回傳的值會是沒有意義的(應該會是被轉型過的)
    return 期間使用 cast（轉型使用時）就不會有warning（在有需要轉型的情況下）
    另外為了讓新版compiler可以相容舊版本的c code:
        所以當我們沒有明確declare一個將要用到的function時,該function會在第一次出現在calling routine的expression裡被declare
        e.g. int a = add(5,3)
        此時該宣告之return type 為預設的 int 當中parameter會被無視（應是Void)
        及 add function 會被 calling routine declare為
        int add(Void) 

## 4.3 External Variables
    External Variables是一種function溝通的橋樑
    只有在宣告後才能用
    external linkage := 指的是如何讓所有分散的.c檔內都指到同一個external variable.
    
## 4.4 Scope Rules
* the scope of an external variable or a function lasts from the point at which it is declared to the end of the file.On the other hand, extern declaration is mandatory.
* the different of declaration and difinition.
e.g.double val[MAXVAL]; and extern double val[];
* 宣告時不用給出明確的記憶體佔用大小定義時給出即可
definition will reserve storage for variable,but declaration not.

* can have only one definition of extern variable.

## 4.5 Header Files
* 中等規模的header寫成一份就好,大規模的則應該拆成多分更有規模

## 4.6 Static Variables
* 當想讓extern variable只可被該文檔的function所存取就在definition時的前方加上extern
* 當你使用static來形容一個extern時,其他檔案就可以再次使用相同變數名稱而不衝突
* Internal變數也可加上static修飾,這麼一來該變數的生命週期就不會隨著該定義他的function啟動或結束而消失,不同的是他會一直有值.

## 4.7 Register Variables
register int x;
register declaration can only be applied to automatic variables and to the formal parameters of a function.

register 宣告建議了compiler 將該變數資料因經常使用而希望存放在machine register中.
過多的register宣告是無害的因為compiler會無視他,且帶有register修飾符會取決於該變數型態以及總體的register變數多寡（跟我們的硬體有關）而決定是否起作用,然而即便該register修是的變數沒被實際放到machine register中,我們也不能存取該變數的位址.

## 4.8 Block Structure
C在任何block內都可以宣告,且其效力在其宣告後致右大括號,並且在程式碼進入該片斷後才initialize,且其名稱可以遮蓋該區快外部的相同變數名稱.

## 4.9 Initialization

沒有特別表明時,external跟static 都會出使化為0,兒automatic 及 register則是undefined(垃圾).

Scalar variable可以在定義時初始化值,e.g. int x = 1;
for external and static variables, the initializer must be a constant expression, 且initial 只做一次大概在程式執行前,相比之下automatic及register的變數初始值就不用是constant的了。
其實initial automatic的變數只是指派敘述的縮寫而已,

array有另一種初始化的方式如下
    int a[] = {5, 5, 10}
這種不給陣列大小的情況下,編譯器會自動計算該陣列所需容量
如果給的初始化值少於該array大小則會自動幫夠面的都補上0
沒辦法漏給array前面的元素

Character array 更特別可以透過
char pattern = "ould"賦值
注意的是上方pattern 陣列大小為5最後包含一個'\0'

## 4.10 Recursion
遞迴很熟了吧
他不一定省空間也不一定會變快

## 4.11 The C Preprocessor




---
## Remain Work & Note

#### remain
 * ex11
#### note
ex 8 9練習 寫在同一c檔案 ex8.c 內
ex 3~7 練習 則寫在同一檔案 ex3.c 內