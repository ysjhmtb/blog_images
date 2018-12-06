package me.yun;


import org.springframework.boot.SpringApplication;
import org.springframework.boot.WebApplicationType;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintStream;
import java.io.PrintWriter;


/*
 더 깊게 들어가서 코드가 어떻게 작동하는지 이해하는 것은 좋다. 하지만 항상 학습하실 때는 가성비를 생각하셔야 한다. - 백기선 

 */

@SpringBootApplication
public class Application {


    public static void main(String[] args) {
        SpringApplication.run(Application.class, args);


    }
}
