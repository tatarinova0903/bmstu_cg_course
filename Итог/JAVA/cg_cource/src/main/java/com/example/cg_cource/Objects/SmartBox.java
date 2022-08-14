package com.example.cg_cource.Objects;

import com.example.cg_cource.Helpers.Constants;
import com.example.cg_cource.Helpers.Material;
import javafx.geometry.Point3D;
import javafx.scene.paint.PhongMaterial;
import javafx.scene.shape.Box;
import javafx.scene.transform.Rotate;
import javafx.scene.transform.Transform;

public class SmartBox extends Box {

    public SmartBox(double v, double v1, double v2, Material material) {
        super(v, v1, v2);
        PhongMaterial phongMaterial = new PhongMaterial();
        phongMaterial.setDiffuseMap(material.getImageForTexture());
        setMaterial(phongMaterial);
    }

    public void translateForBack() {
        setRotationAxis(new Point3D(1, 0, 0));
        setRotate(90);
        setTranslateZ(Constants.Room.SIZE / 2);
    }

    public void translateForLeft() {
        setRotate(90);
        setTranslateX(- Constants.Room.SIZE / 2);
    }

    public void translateForRight() {
        setRotate(90);
        setTranslateX(Constants.Room.SIZE / 2);
    }
}
