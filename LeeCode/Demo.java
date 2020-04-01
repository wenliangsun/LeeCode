
class Demo {
    public static void main(String[] args) {
        // String s = null;
        Demo d = new Demo();
        d.demo(null);
    }

    public void demo(String s) {
        if(s==null){
            System.out.println("null!!!");
        }
    }
}