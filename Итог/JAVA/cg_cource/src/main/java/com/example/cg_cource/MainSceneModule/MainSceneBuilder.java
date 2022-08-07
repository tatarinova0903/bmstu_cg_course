package com.example.cg_cource.MainSceneModule;

import com.example.cg_cource.Helpers.ScreenConstants;
import javafx.scene.Group;

public class MainSceneBuilder {
    public static MainScene build() {
        MainGroup mainGroup = new MainGroup();
        MainScene scene = new MainScene(mainGroup, ScreenConstants.WIDTH, ScreenConstants.HEIGHT);
        return scene;
    }
}
