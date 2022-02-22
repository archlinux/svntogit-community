# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: Eli Schwartz <eschwartz@archlinux.org>
# Contributor: George Rawlinson <george@rawlinson.net.nz>

_pkgname=poetry-core
pkgname=python-poetry-core
pkgver=1.0.7
pkgrel=4
pkgdesc="Poetry PEP 517 Build Backend & Core Utilities"
arch=('any')
url="https://github.com/python-poetry/${_pkgname}"
license=('MIT')
_deps=('jsonschema' 'lark-parser' 'packaging' 'tomlkit')
depends=("${_deps[@]/#/python-}")
makedepends=(python-{build,installer})
checkdepends=(git python-pytest python-pytest-mock python-virtualenv)
conflicts=('python-poetry<1.1.0')
_archive="$_pkgname-$pkgver"
source=("$url/archive/$pkgver/$_archive.tar.gz")
sha256sums=('a4a99d2d0adb54d69acaa6d852bc9d41818b5a2d751aa23a9543e32bc4e6660d')
b2sums=('570f13e3c7298fd822a38b75c49c623bde4fa780b3787c3c9cfa3939bb68fee3eeaf6190013117a6e751cb6f87a15b343ba183529fcc07d30e37988097954d4a')

prepare() {
	cd "$_archive"
	# remove vendored dependencies
	sed -i '/^__version__/!d' poetry/core/__init__.py
	rm -r poetry/core/_vendor
}

build() {
	cd "$_archive"
	python -m build -wn
}

check() {
	cd "$_archive"
	# only works inside git repositories
	pytest \
		-k 'not test_default_with_excluded_data and not test_default_src_with_excluded_data'
}

package() {
	cd "$_archive"
	python -m installer -d "$pkgdir" dist/*.whl
	install -Dm0644 -t "$pkgdir/usr/share/licenses/$pkgname/" LICENSE
}
