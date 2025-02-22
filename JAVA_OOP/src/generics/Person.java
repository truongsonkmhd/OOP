package generics;

public class Person<T,A> {
    private T id ;
    private A age;
    public Person(T id, A age){
        this.id = id;
        this.age = age;
    }

    public T getId(){
        return id;
    }

    public A getAge(){
        return age;
    }
}
