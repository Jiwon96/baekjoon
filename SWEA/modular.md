# 모듈러 연산
* 소수 p로 나눈 나머지를 구해라.
  * 먼저 N의 역수의 모둘러 연산은 $N^{p-2}$ %p 이다.


```cpp
long long function(num){
  long long ret =1;
  while(i){
    if(i%2==1)
      ret = num*ret%p;
    i/=2;
    num = num*num%p;
  }
return ret;
}
```
