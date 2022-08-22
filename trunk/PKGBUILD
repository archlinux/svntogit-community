# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: Sven-Hendrik Haase <svenstaro@gmail.com>
# Contributor: Eli Schwartz <eschwartz@archlinux.org>

BUILDENV+=(!check)

_pkgname=poetry
pkgname=python-poetry
pkgver=1.1.15
pkgrel=1
pkgdesc='Python dependency management and packaging made easy'
arch=(any)
url=https://python-poetry.org
license=(MIT)
_deps=(cachecontrol
       cachy
       cleo
       html5lib
       keyring
       lockfile
       packaging
       pexpect
       pkginfo
       poetry-core
       requests
       requests-toolbelt
       shellingham
       tomlkit
       virtualenv)
depends=("${_deps[@]/#/python-}")
makedepends=(python-{build,installer})
checkdepends=(git
              python-httpretty
              python-pytest
              python-pytest-mock)
provides=(poetry)
_archive="$_pkgname-$pkgver"
source=("https://github.com/$pkgname/$_pkgname/archive/$pkgver/$_archive.tar.gz"
        0001-Suppress-dependency-versions-which-are-known-to-be-t.patch
        0001-tests-cleanup-cache-and-http-usage.patch
        poetry-completions-generator
        https://github.com/felixonmars/poetry/commit/b4a74c7.patch)
sha256sums=('806faa098b43e2264183bd1d45d7014e4f03e7e924d7b33e8cf3156be77e3c7b'
            '06afd8fc75287658d7b240b6eac9e4b84e36f8393545bc6c2c45170a818cadff'
            '4658321c04f36fb3aced9acc44b61f2cf22c5f9d8b8c715111881b24c3e0c99b'
            '970225289188ea8dc49fbec8a2bfe0c891aee80ff56ba6e69bdd8afef8bccab6'
            '44802ac51dc4f41f661c691b3ffe1ac892df6a5b0cb67d072348a0d15ae660e5')

prepare() {
	cd "$_archive"
	# fix various overly restrictive version pinning
	patch -p1 -i ../0001-Suppress-dependency-versions-which-are-known-to-be-t.patch
	# fix tests trying to write to the root directory
	# See: https://github.com/python-poetry/poetry/issues/1645
	patch -p1 -i ../0001-tests-cleanup-cache-and-http-usage.patch
	install -m0755 -t ./ ../poetry-completions-generator
	# https://github.com/python-poetry/poetry/issues/5216
	patch -p1 -i ../b4a74c7.patch
        # relax dependency version constraints
        sed -e 's|packaging = .*|packaging = \">=20.4\"|' -i pyproject.toml
}

build() {
	cd "$_archive"
	python -m build -wn
}

check() {
	cd "$_archive"
	# tries to write all over sys.executable's containing directory, and fails
	# use venv instead
	# See (again): https://github.com/python-poetry/poetry/issues/1645
	# python -m venv --system-site-packages --without-pip poetrytests
	# ./poetrytests/bin/python -m pytest
}

package() {
	cd "$_archive"
	python -m installer -d "$pkgdir" dist/*.whl
	install -Dm0644 -t "$pkgdir/usr/share/licenses/$pkgname/" LICENSE
	# install completions, which for some crazy reason hardcode the filename
	# used to invoke which is __main__.py if we use python -m poetry, and also
	# adds the full directory path???
	./poetry-completions-generator completions bash |
		sed "#$srcdir#d" |
		install -Dm644 /dev/stdin "$pkgdir/usr/share/bash-completion/completions/poetry"
	./poetry-completions-generator completions zsh |
		sed "#$srcdir#d" |
		install -Dm644 /dev/stdin "$pkgdir/usr/share/zsh/site-functions/_poetry"
	./poetry-completions-generator completions fish |
		install -Dm644 /dev/stdin "$pkgdir/usr/share/fish/vendor_completions.d/poetry.fish"
}
