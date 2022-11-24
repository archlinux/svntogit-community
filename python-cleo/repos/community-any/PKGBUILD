# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=cleo
pkgname=python-cleo
pkgver=2.0.0
pkgrel=1
pkgdesc="create beautiful and testable command-line interfaces"
arch=(any)
url="https://github.com/python-poetry/$_pkgname"
license=(MIT)
depends=(python-crashtest
         python-pylev)
makedepends=(python-{build,installer,wheel}
             python-poetry-core)
checkdepends=(python-pytest
              python-pytest-mock
              python-rapidfuzz)
_archive="$_pkgname-$pkgver"
source=("$url/archive/$pkgver/$_archive.tar.gz")
sha256sums=('3f46178e2cd0e76c0f1f763e48f9053ef5bd6c77111899607f897a1a81ea7b1d')
b2sums=('98d7834b674253cd93574ba57b81247fa987f23afb251bbb62e5f237514001e88522003a753251e5a0d7cd5d810f90315b7c70b979d28871ae3fe4296924d620')

prepare() {
    cd "$_archive"
    # we do not use overly strict version constraints
    sed -e 's/\^/>=/g' \
        -e 's/~=/>=/g' \
        -i pyproject.toml
}

build(){
    cd "$_archive"
    python -m build -wn
}

check() {
    cd "$_archive"
    export PYTHONPATH="$PWD/src"
    pytest -vv
}

package() {
    cd "$_archive"
    python -m installer -d "$pkgdir" dist/*.whl
    install -Dm0644 -t "$pkgdir/usr/share/licenses/$pkgname/" LICENSE
}
