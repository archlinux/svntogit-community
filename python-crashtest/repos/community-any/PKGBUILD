# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=crashtest
pkgname=python-crashtest
pkgver=0.4.0
pkgrel=1
pkgdesc='supposedly makes exceptions handling and inspection easier'
arch=(any)
url="https://github.com/sdispater/${_pkgname}"
license=(MIT)
depends=(python)
makedepends=(python-{build,installer,wheel}
             python-poetry)
checkdepends=(python-pytest)
_archive="$_pkgname-$pkgver"
source=("$url/archive/$pkgver/$_archive.tar.gz")
sha256sums=('fe89907fc06ca3c5fbd7175d2001a150929297badef177e17ed2b662045cf86e')
b2sums=('9c29694f5c96a981e19cce16853460cfed7277a2a933c14be9bdefcac9f79e9d835454fd79b3da2fb5f62946f933452202eee05199dfa048b919a3fc3dd93f40')

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
