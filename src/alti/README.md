cgreen と define での置き換え
========================================

# コマンド
```
cmake -S . -B $(BUILD)
# もしくは
cmake -S . -B $(BUILD) -DBUILD_TEST=ON
cmake --build $(BUILD)
ctest --test-dir $(BUILD)
```

```
cgreen-runner ./build_test/test/libtest_fizzbuzz.so -v
```

# やってること

``` -DBUILD_TST ``` を渡すと、
```write_console.c check_print_console.c``` のファイルのifdefで効いて、printfがテスト用のモックに入れ替えられて動く。
