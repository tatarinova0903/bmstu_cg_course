package com.example.cg_cource;

import com.example.cg_cource.MainSceneModule.MainScene;
import com.example.cg_cource.MainSceneModule.MainSceneBuilder;
import com.example.cg_cource.MenuModule.MenuScene;
import com.example.cg_cource.MenuModule.MenuSceneBuilder;
import com.example.cg_cource.MenuModule.MenuStack;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class MainApplication extends Application {
    @Override
    public void start(Stage stage) throws IOException {
        MainScene scene = MainSceneBuilder.build();
        stage.setScene(scene);
        stage.setTitle("Курсовая работа");
        stage.setHeight(800);
        stage.setWidth(1100);
        stage.setX(320);
        stage.show();

        MenuScene menuScene = MenuSceneBuilder.build(scene.getGroup());
        Stage menuStage = new Stage();
        menuStage.setScene(menuScene);
        menuStage.setHeight(800);
        menuStage.setWidth(300);
        menuStage.setTitle("Меню");
        menuStage.setX(20);
        menuStage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}