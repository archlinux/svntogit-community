# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: Eli Schwartz <eschwartz@archlinux.org>
# Contributor: George Rawlinson <george@rawlinson.net.nz>

_pkgname=poetry-core
pkgname=python-poetry-core
pkgver=1.5.1
pkgrel=1
pkgdesc='Poetry PEP 517 Build Backend & Core Utilities'
arch=('any')
url="https://github.com/python-poetry/${_pkgname}"
license=('MIT')
_pydeps=(jsonschema
         lark-parser
         packaging
         tomlkit)
depends=("${_pydeps[@]/#/python-}")
makedepends=(python-{build,installer})
checkdepends=(git
              python-pytest
              python-pytest-mock
              python-setuptools
              python-virtualenv)
conflicts=('python-poetry<1.1.0')
_archive="$_pkgname-$pkgver"
source=("$url/archive/$pkgver/$_archive.tar.gz")
sha256sums=('cfbff7b4d3cfb7c1679bb8699ac1053abddd1e853b7eb3c64491683f2caadd2f')

build() {
	cd "$_archive"
	python -m build -wn
}

check() {
	cd "$_archive"
	export PYTHONPATH="$PWD/src"
	# only works inside git repositories
	pytest \
		-k 'not test_default_with_excluded_data and not test_default_src_with_excluded_data'
}

package() {
	cd "$_archive"
	python -m installer -d "$pkgdir" dist/*.whl
	install -Dm0644 -t "$pkgdir/usr/share/licenses/$pkgname/" LICENSE
}
