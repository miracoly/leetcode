{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-24.11";
  };

  outputs = {nixpkgs, ...}: let
    system = "x86_64-linux";
    pkgs = import nixpkgs {inherit system;};
  in {
    devShell.${system} = pkgs.mkShell {
      buildInputs = with pkgs; [
        criterion
        gcc
        gnumake
        gtest
        uthash
      ];
      shellHook = ''
        bear -- make > /dev/null 2>&1
      '';
    };
  };
}
