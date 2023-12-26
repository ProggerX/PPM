{
	inputs = {
		nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
	};

	outputs = {self, nixpkgs}:
	let system = "x86_64-linux";
	pkgs = import nixpkgs { inherit system; };
	in {
		packages."${system}".default = pkgs.stdenv.mkDerivation {
			# Main info
			name = "ppm";
			src = ./.;

			# Dependencies
			nativeBuildInputs = with pkgs; [
				just
				gcc
			];
			buildInputs = with pkgs; [
				ncurses
			];
			
			# Phases
			buildPhase = "just build"; # Build project using just (justfile)
			installPhase = "cp out $out"; # Copy output to 'result' (symlink appears in this directory, if you run "nix build")
		};
		devShells."${system}".default = pkgs.mkShell {
			packages = [
				self.packages."${system}".default.nativeBuildInputs
				self.packages."${system}".default.buildInputs
				pkgs.bear
			];
		};
	};
}
