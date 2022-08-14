package com.example.cg_cource;

import com.example.cg_cource.Helpers.Constants;
import com.example.cg_cource.MainSceneModule.MainScene;
import com.example.cg_cource.MainSceneModule.MainSceneBuilder;
import com.example.cg_cource.MenuModule.MenuScene;
import com.example.cg_cource.MenuModule.MenuSceneBuilder;
import javafx.application.Application;
import javafx.stage.Stage;

import java.io.IOException;

public class MainApplication extends Application {
    @Override
    public void start(Stage stage) throws IOException {
        MainScene mainScene = MainSceneBuilder.build();
        stage.setScene(mainScene);
        stage.setTitle("Курсовая работа");
        stage.setHeight(Constants.Main.HEIGHT);
        stage.setWidth(Constants.Main.WIDTH);
        stage.setX(Constants.Menu.WIDTH + Constants.Screen.HORIZ_PADDING);
        stage.show();

        MenuScene menuScene = MenuSceneBuilder.build(mainScene.getGroup());
        Stage menuStage = new Stage();
        menuStage.setScene(menuScene);
        menuStage.setHeight(Constants.Main.HEIGHT);
        menuStage.setWidth(Constants.Menu.WIDTH);
        menuStage.setTitle("Меню");
        menuStage.setX(Constants.Screen.HORIZ_PADDING);
        menuStage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}