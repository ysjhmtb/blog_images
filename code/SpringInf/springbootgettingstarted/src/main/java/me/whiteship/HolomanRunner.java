package me.whiteship;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.ApplicationArguments;
import org.springframework.boot.ApplicationRunner;

public class HolomanRunner implements ApplicationRunner {

    // 이 프로젝트 어디서도 Holoman을 빈으로 등록하지 않았지만 사용하고 있다.
    @Autowired
    Holoman holoman;

    @Override
    public void run(ApplicationArguments args) throws Exception {
        System.out.println(holoman);

    }
}
