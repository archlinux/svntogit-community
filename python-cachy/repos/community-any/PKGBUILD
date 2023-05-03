# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=cachy
pkgname=python-cachy
pkgver=0.3.0
pkgrel=9
pkgdesc='simple yet effective caching library'
arch=(any)
url="https://github.com/sdispater/${_pkgname}"
license=(MIT)
depends=(python)
makedepends=(python-{build,installer,wheel}
             python-poetry-core)
_checkdeps=(flexmock pytest-mock memcached fakeredis)
checkdepends=("${_checkdeps[@]/#/python-}"
              pifpaf
              memcached)
_archive="$_pkgname-$pkgver"
source=("https://files.pythonhosted.org/packages/source/${_pkgname:0:1}/$_pkgname/$_archive.tar.gz"
        fix-flexmock_teardown-import.patch)
sha256sums=('186581f4ceb42a0bbe040c407da73c14092379b1e4c0e327fdb72ae4a9b269b1'
            'f00e7f140e30dac30953fe56132d4bcd9d782e534e300619f68309f4eb6385a9')
b2sums=('df2d1356a309707af5aea9aa0e534130f21815da58988a5623feb3fff3d97de655c3977a80dcf8eaefe47d9d14d8e6e6a4bab0f8afd8d42668ed061172c0a1c7'
        '794944aecd2d395ec1e35cce8d7dd7b78080e7693768a3594f2dd2607fab951a4ac3bea7bb2e80a5dd399af65a6215ff0309a1df59861559b8975130b1ec00a8')

prepare() {
	cd "$_archive"
	patch -Np1 -i ../fix-flexmock_teardown-import.patch
}

build(){
	cd "$_archive"
	python -m build -wn
}

check() {
	cd "$_archive"
	pifpaf run memcached --port 11211 -- pytest
}

package() {
	cd "$_archive"
	python -m installer -d "${pkgdir}" dist/*.whl
	install -Dm0644 -t "$pkgdir/usr/share/licenses/$pkgname/" LICENSE
	local _py3_ver=$(python --version | cut -d " " -f2)
	rm -rf "$pkgdir/usr/lib/python${_py3_ver%.*}/site-packages/tests"
}
