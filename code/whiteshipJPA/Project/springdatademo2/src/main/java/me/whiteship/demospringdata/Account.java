package me.whiteship.demospringdata;

import javax.persistence.*;
import java.util.Date;

/*
@Entity이기 때문에 자동으로 테이블로 매핑이 됨. @Table이라는 애너테이션도 생략이 되어 있는 것임.
@Entity에는 이름을 줄 수 있음. 기본적으로 클래스의 이름과 동일한 이름을 사용함.
@Entity(name="myAccount")처럼 이름을 변경할 수도 있는데, 이는 하이버네이트 내부에서만 사용하는 이름.

DB에서는 User라는 이름을 사용할 수 없는데(PostgreSQL의 키워드), 코드에서는 User라는 이름을 사용해야 할 수도 있음. 이런 경우에는

@Entity(name = "users")
public class User

로 작성해야 한다.
*/
@Entity
public class Account {

    @Id
    @GeneratedValue
    private Long id;

    // @Column이 생략되어 있음.
    @Column(nullable = false, unique = true)
    private String username;

    private String password;

    @Temporal(TemporalType.TIMESTAMP)
    private Date created = new Date();

    private String yes;

    // DB에 매핑할 필요는 없이 코드에서만 사용할 경우 @Transient를 사용.
    @Transient
    private String no;

    @Embedded
    @AttributeOverrides({
            @AttributeOverride(name = "street", column = @Column(name = "home_street"))
    })
    private Address address;


    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }
}
