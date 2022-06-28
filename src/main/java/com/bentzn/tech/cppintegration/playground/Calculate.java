package com.bentzn.tech.cppintegration.playground;

public class Calculate {

    static {
        System.loadLibrary("native");
    }

    public native int calculate();

    public static void main(String[] args) {
        Calculate cCalc = new Calculate();

        long nTime0 = System.currentTimeMillis();
        for (int i = 0; i < 100; i++) {
            cCalc.calculate();
        }
        double nTimeD = (System.currentTimeMillis() - nTime0) / 1000d;
        System.out.println("Frames/sec: " + 100 / nTimeD);
    }
}

/*-
    cd ./src/main/java/com/bentzn/tech/cppintegration/playground/
    javac -h . Calculate.java
    g++ -c -fPIC -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux com_bentzn_tech_cppintegration_playground_Calculate.cpp -o com_bentzn_tech_cppintegration_playground_Calculate.o
    g++ -shared -fPIC -o libnative.so com_bentzn_tech_cppintegration_playground_Calculate.o -lc
    cd ../../../../../
    java -cp . -Djava.library.path=./com/bentzn/tech/cppintegration/playground com.bentzn.tech.cppintegration.playground.Calculate
*/
