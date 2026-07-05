{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-26.05";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = {
    nixpkgs,
    flake-utils,
    ...
  }:
    flake-utils.lib.eachDefaultSystem (system: let
      pkgs = import nixpkgs {inherit system;};
    in {
      devShells.default = pkgs.mkShell {
        nativeBuildInputs = with pkgs; [
          clang-tools
          criterion
          gcc
          gnumake
          leetgo
        ];
        buildInputs = with pkgs; [
          uthash
          gtest
        ];
        shellHook = ''
          bear -- make > /dev/null 2>&1
        '';
      };
    });
}
