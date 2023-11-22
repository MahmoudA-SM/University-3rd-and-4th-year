public class A {
    public void method1() {
        b.STATIC_INSTANCE.method2();
    }
}
    
    class B {
    public static final B STATIC_INSTANCE = ...;
    public void method2() {
        //wtv
    }
}