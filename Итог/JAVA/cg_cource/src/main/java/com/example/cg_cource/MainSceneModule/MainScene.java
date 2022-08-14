package com.example.cg_cource.MainSceneModule;

import javafx.scene.Camera;
import javafx.scene.Parent;
import javafx.scene.PerspectiveCamera;
import javafx.scene.Scene;
import javafx.scene.paint.Color;

public class MainScene extends Scene {
    private Camera camera = new PerspectiveCamera(true);
    private MainGroup group;

    public MainScene(Parent parent, double v, double v1) {
        super(parent, v, v1);
        group = (MainGroup) parent;
        setFill(Color.WHITE);
        setCamera(camera);

        camera.translateZProperty().set(-1000);

        camera.setNearClip(1);
        camera.setFarClip(1500);
    }

    public MainGroup getGroup() {
        return group;
    }
}
