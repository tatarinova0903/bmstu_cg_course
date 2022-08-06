package com.example.cg_cource;

import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.input.KeyEvent;
import javafx.stage.Stage;

import java.io.IOException;

public class MainApplication extends Application {
    @Override
    public void start(Stage stage) throws IOException {
        MainController mainPane = new MainController();
        Scene scene = new Scene(mainPane);
        stage.setScene(scene);
        stage.setTitle("Курсовая работа");
        stage.setHeight(800);
        stage.setWidth(1300);
        scene.setOnKeyPressed(new EventHandler<KeyEvent>() {
            public void handle(KeyEvent ke) {
                mainPane.keyboardDidTap(ke);
            }
        });
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}