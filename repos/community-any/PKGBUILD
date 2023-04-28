# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: Felix Yan <felixonmars@archlinux.org>
# Contributor: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=tomlkit
pkgname=python-tomlkit
pkgver=0.11.8
pkgrel=1
pkgdesc='Style-preserving TOML library for Python'
url="https://github.com/sdispater/$_pkgname"
license=(MIT)
arch=(any)
depends=(python)
makedepends=(python-{build,installer,wheel}
             python-poetry-core)
checkdepends=(python-pytest
              python-yaml)
_archive="$_pkgname-$pkgver"
source=("https://files.pythonhosted.org/packages/source/${_pkgname::1}/$_pkgname/$_archive.tar.gz")
sha256sums=('9330fc7faa1db67b541b28e62018c17d20be733177d290a13b24c62d1614e0c3')

build() {
	cd "$_archive"
	python -m build -wn
}

check() {
	cd "$_archive"
	pytest
}

package() {
	cd "$_archive"
	python -m installer -d "$pkgdir" dist/*.whl
	install -Dm0644 -t "$pkgdir/usr/share/licenses/$pkgname/" LICENSE
}
