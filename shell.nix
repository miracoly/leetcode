{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
    buildInputs = with pkgs.buildPackages; [
        gnumake
        gcc
        uthash
    ];
}