package com.example.cg_cource;

import javafx.scene.image.Image;

import java.io.InputStream;

public class Material {
    private MaterialType materialType;

    public Material(MaterialType materialType) {
        this.materialType = materialType;
    }

    public MaterialType getMaterialType() {
        return materialType;
    }

    public void setMaterialType(MaterialType materialType) {
        this.materialType = materialType;
    }

    public Image getImageForTexture() {
        InputStream inputStream = null;
        switch (materialType) {
            case WOOD -> inputStream = getClass().getResourceAsStream("/images/wood.jpg");
            case PAPER -> inputStream = getClass().getResourceAsStream("/images/paper.jpg");
            case PLASTIC -> inputStream = getClass().getResourceAsStream("/images/plastic.jpg");
        }
        return new Image(inputStream);
    }
}
