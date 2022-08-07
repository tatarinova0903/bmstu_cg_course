package com.example.cg_cource.MainSceneModule;

import com.example.cg_cource.ScreenConstants;

public class MainSceneBuilder {
    public static MainScene build() {
        MainGroup mainPane = new MainGroup();
        MainScene scene = new MainScene(mainPane, ScreenConstants.WIDTH, ScreenConstants.HEIGHT);
        return scene;
    }
}
