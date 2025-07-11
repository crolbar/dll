{
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";

  outputs = inputs: let
    system = "x86_64-linux";
    pkgs = import inputs.nixpkgs {inherit system;};
  in {
    packages.${system}.default = pkgs.stdenv.mkDerivation {
      pname = "dll";
      version = "0.1";
      src = ./.;
      installPhase = ''
        runHook preInstall

        mkdir -p $out/include
        cp dll.h $out/include/

        runHook postInstall
      '';
    };
  };
}
