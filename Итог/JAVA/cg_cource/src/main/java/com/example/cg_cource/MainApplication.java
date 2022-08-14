package com.example.cg_cource;

import com.example.cg_cource.Helpers.ScreenConstants;
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
        stage.setHeight(ScreenConstants.Main.HEIGHT);
        stage.setWidth(ScreenConstants.Main.WIDTH);
        stage.setX(ScreenConstants.Menu.WIDTH + ScreenConstants.Screen.HORIZ_PADDING);
        stage.show();

        MenuScene menuScene = MenuSceneBuilder.build(mainScene.getGroup());
        Stage menuStage = new Stage();
        menuStage.setScene(menuScene);
        menuStage.setHeight(ScreenConstants.Main.HEIGHT);
        menuStage.setWidth(ScreenConstants.Menu.WIDTH);
        menuStage.setTitle("Меню");
        menuStage.setX(ScreenConstants.Screen.HORIZ_PADDING);
        menuStage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}