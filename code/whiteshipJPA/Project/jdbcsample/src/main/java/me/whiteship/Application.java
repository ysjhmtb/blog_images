package me.whiteship;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;

public class Application {
    public static void main(String[] args) {
        String url = "jdbc:postgresql://localhost:5432/springdata";
        String username = "yun";
        String password = "pass";

        /*
        Project Structure >> Project Settings >> Modules >> Language level >> 8
         */
        try (Connection connection = DriverManager.getConnection(url, username, password)) {
            System.out.println("Connection created: " + connection);
//            String sql = "CREATE TABLE ACCOUNT (id int, username varchar(255), password varchar(255));";
            String sql = "INSERT INTO ACCOUNT VALUES(1,'keesun','pass')";

            try (PreparedStatement statement = connection.prepareStatement(sql)) {
                statement.execute();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
