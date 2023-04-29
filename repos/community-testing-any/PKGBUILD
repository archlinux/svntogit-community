# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=crashtest
pkgname=python-crashtest
pkgver=0.4.1
pkgrel=2
pkgdesc='supposedly makes exceptions handling and inspection easier'
arch=(any)
url="https://github.com/sdispater/${_pkgname}"
license=(MIT)
depends=(python)
makedepends=(python-{build,installer,wheel}
             python-poetry-core)
checkdepends=(python-pytest)
_archive="$_pkgname-$pkgver"
source=("$url/archive/$pkgver/$_archive.tar.gz")
sha256sums=('4ff59d9bee6d2bc581d462888ec28beb30ad448042c885a2b4ab45dc4910780b')
b2sums=('aa46efb2dbabfeaab54f9149da42cb033f5dca3ab1c75032ca2542018058cf16775f56450cadf3e1272e738d602f32f21b9a6668a99f2733cd53d23c1754a0bc')

build(){
	cd "$_archive"
	python -m build -wn
}

check() {
	cd "$_archive"
	python -m pytest
}

package() {
	cd "$_archive"
	python -m installer -d "${pkgdir}" dist/*.whl
	install -Dm0644 -t "$pkgdir/usr/share/licenses/$pkgname/" LICENSE
}
