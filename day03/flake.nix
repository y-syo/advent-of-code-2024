{
  description = "a minimal test development environment for ruby";

  inputs = {

    nixpkgs = {
      url = "nixpkgs/nixos-24.05";
      flake = false;
	};

  };

  outputs = inputs@{ nixpkgs, ... }:
	{
    devShell = {
      x86_64-linux = let
        pkgs = import nixpkgs { system = "x86_64-linux"; };
	  in pkgs.mkShell {
        packages = with pkgs; [
          gcc ruby
        ];
        shellHook = ''
          export CC=gcc
          echo -e "\x1B[0;33mentering ruby minimalist test development environment...\x1B[0m"
        '';
      };
    };
  };
}
