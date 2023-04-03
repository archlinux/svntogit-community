# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: David Joaquín Shourabi Porcel <david@djsp.eu>
# Contributor: Sven-Hendrik Haase <svenstaro@gmail.com>
# Contributor: Eli Schwartz <eschwartz@archlinux.org>

BUILDENV+=(!check)

_pkgname=poetry
pkgname=python-poetry
pkgver=1.4.2
pkgrel=1
pkgdesc='Python dependency management and packaging made easy'
arch=(any)
url=https://python-poetry.org
license=(MIT)
_deps=(build
       cachecontrol
       cachy
       cleo
       crashtest
       dulwich
       html5lib
       installer
       jsonschema
       keyring
       lockfile
       packaging
       pexpect
       pkginfo
       platformdirs
       poetry-core
       poetry-plugin-export
       requests
       requests-toolbelt
       shellingham
       tomli
       tomlkit
       urllib3
       virtualenv)
depends=("${_deps[@]/#/python-}")
makedepends=(python)
checkdepends=(git
              python-httpretty
              python-pytest
              python-pytest-mock)
provides=(poetry)
_archive="$_pkgname-$pkgver"
source=("https://github.com/$pkgname/$_pkgname/archive/$pkgver/$_archive.tar.gz"
        poetry-completions-generator)
sha256sums=('8cdbad22dfd11ca9c7e37bcafe18ae931b80e0776adbe6df8d24091bd2b23eff'
            'e44c71a3b804b5c2bf07573ed465aee275a5844f10e37ee63c7395c9213a2b6d')

prepare() {
	cd "$_archive"
	install -m0755 -t ./ ../poetry-completions-generator
	# Unpin crashtest which we have packaged at 0.4.0
	# https://bugs.archlinux.org/task/75733
	sed -i -e '/^crashtest/s/\^/>=/' pyproject.toml
}

build() {
	cd "$_archive"
	python -m build -wn
}

check() {
	cd "$_archive/src"
	export PYTHONPATH="$PWD"
	pytest
}

package() {
	cd "$_archive"
	python -m installer -d "$pkgdir" dist/*.whl
	install -Dm0644 -t "$pkgdir/usr/share/licenses/$pkgname/" LICENSE
	# install completions, which for some crazy reason hardcode the filename
	# used to invoke which is __main__.py if we use python -m poetry, and also
	# adds the full directory path???
	set -o pipefail
	./poetry-completions-generator completions bash |
		sed "#$srcdir#d" |
		install -Dm644 /dev/stdin "$pkgdir/usr/share/bash-completion/completions/poetry"
	./poetry-completions-generator completions zsh |
		sed "#$srcdir#d" |
		install -Dm644 /dev/stdin "$pkgdir/usr/share/zsh/site-functions/_poetry"
	./poetry-completions-generator completions fish |
		install -Dm644 /dev/stdin "$pkgdir/usr/share/fish/vendor_completions.d/poetry.fish"
}
