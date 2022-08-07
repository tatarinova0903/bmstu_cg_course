package com.example.cg_cource.MainSceneModule;

import javafx.scene.Camera;
import javafx.scene.Parent;
import javafx.scene.PerspectiveCamera;
import javafx.scene.Scene;
import javafx.scene.input.KeyEvent;
import javafx.scene.paint.Color;

public class MainScene extends Scene {
    private static final double COORD_CHANGE = 50;
    private Camera camera = new PerspectiveCamera(true);
    private MainGroup group;

    public MainScene(Parent parent, double v, double v1) {
        super(parent, v, v1);
        group = (MainGroup) parent;
        setFill(Color.WHITE);
        setCamera(camera);

        camera.translateZProperty().set(-500);

        camera.setNearClip(1);
        camera.setFarClip(1000);
    }

    public void keyboardDidTap(KeyEvent keyEvent) {
        switch (keyEvent.getCode()) {
            case W -> group.roomGroup.translateZProperty().set(group.roomGroup.getTranslateZ() + COORD_CHANGE);
            case S -> group.roomGroup.translateZProperty().set(group.roomGroup.getTranslateZ() - COORD_CHANGE);
            case UP -> group.roomGroup.rotateByX(-10);
            case DOWN -> group.roomGroup.rotateByX(10);
            case LEFT -> group.roomGroup.rotateByY(10);
            case RIGHT -> group.roomGroup.rotateByY(-10);
        }
    }
}
