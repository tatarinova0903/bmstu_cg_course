package com.example.cg_cource;

import com.example.cg_cource.MainSceneModule.MainGroup;
import com.example.cg_cource.MainSceneModule.MainScene;
import com.example.cg_cource.MainSceneModule.MainSceneBuilder;
import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.scene.input.KeyEvent;
import javafx.stage.Stage;

import java.io.IOException;

public class MainApplication extends Application {
    @Override
    public void start(Stage stage) throws IOException {
        MainScene scene = MainSceneBuilder.build();
        stage.setScene(scene);
        stage.setTitle("Курсовая работа");
        stage.setHeight(800);
        stage.setWidth(1300);
        scene.setOnKeyPressed(new EventHandler<KeyEvent>() {
            public void handle(KeyEvent ke) {
                scene.keyboardDidTap(ke);
            }
        });
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}