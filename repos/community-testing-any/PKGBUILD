# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: Sven-Hendrik Haase <svenstaro@gmail.com>
# Contributor: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=poetry
pkgname=python-poetry
pkgver=1.1.12
pkgrel=2
pkgdesc='Python dependency management and packaging made easy'
arch=(any)
url='https://poetry.eustace.io'
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
makedepends=(python-dephell)
checkdepends=(git
              python-httpretty
              python-pytest
              python-pytest-mock)
provides=(poetry)
_archive="$_pkgname-$pkgver"
source=("$_archive.tar.gz::https://github.com/sdispater/$_pkgname/archive/$pkgver.tar.gz"
        0001-Suppress-dependency-versions-which-are-known-to-be-t.patch
        0001-tests-cleanup-cache-and-http-usage.patch
        poetry-completions-generator)
sha256sums=('9e43946a1a1e021ad7ed579470dc847d53dc3f7db5aeeec380c1064a7d5bff3d'
            'db185e7c46a2c747baa4ed19f131a47f072aa149607a6076d23e64e0c766496a'
            '4658321c04f36fb3aced9acc44b61f2cf22c5f9d8b8c715111881b24c3e0c99b'
            '970225289188ea8dc49fbec8a2bfe0c891aee80ff56ba6e69bdd8afef8bccab6')

prepare() {
	cd "$_archive"
	# fix various overly restrictive version pinning
		patch -p1 -i ../0001-Suppress-dependency-versions-which-are-known-to-be-t.patch
	# fix tests trying to write to the root directory
	# See: https://github.com/python-poetry/poetry/issues/1645
	patch -p1 -i ../0001-tests-cleanup-cache-and-http-usage.patch
	dephell deps convert --from pyproject.toml --to setup.py
}

build() {
	cd "$_archive"
	python setup.py build
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
	python setup.py install --root="${pkgdir}" --optimize=1 --skip-build
	install -Dm644 LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE
	# install completions, which for some crazy reason hardcode the filename
	# used to invoke which is __main__.py if we use python -m poetry, and also
	# adds the full directory path???
	install -m755 "${srcdir}"/poetry-completions-generator ./poetry-completions-generator
	./poetry-completions-generator completions bash | sed "\|${srcdir}|d" | \
		install -Dm644 /dev/stdin "${pkgdir}"/usr/share/bash-completion/completions/poetry
	./poetry-completions-generator completions zsh | sed "\|${srcdir}|d" | \
		install -Dm644 /dev/stdin "${pkgdir}"/usr/share/zsh/site-functions/_poetry
	./poetry-completions-generator completions fish | \
		install -Dm644 /dev/stdin "${pkgdir}"/usr/share/fish/vendor_completions.d/poetry.fish
}
