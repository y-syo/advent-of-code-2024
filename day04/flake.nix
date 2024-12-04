{
  description = "a test development environment for python";

  inputs = {

    nixpkgs = {
      url = "nixpkgs/nixos-24.11";
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
          gcc python3
        ];
        shellHook = ''
          echo -e "\x1B[0;33mentering python test development environment...\x1B[0m"
        '';
      };
    };
  };
}
