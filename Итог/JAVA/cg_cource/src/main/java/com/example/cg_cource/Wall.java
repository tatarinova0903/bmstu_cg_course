package com.example.cg_cource;

import javafx.scene.image.Image;
import javafx.scene.paint.PhongMaterial;
import javafx.scene.shape.Box;

public class Wall extends Box {

    public Wall(double v, double v1, double v2, Material material) {
        super(v, v1, v2);
        PhongMaterial phongMaterial = new PhongMaterial();
        phongMaterial.setDiffuseMap(material.getImageForTexture());
        setMaterial(phongMaterial);
    }
}
