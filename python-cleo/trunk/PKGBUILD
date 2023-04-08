# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=cleo
pkgname=python-cleo
pkgver=2.0.1
pkgrel=4
pkgdesc="create beautiful and testable command-line interfaces"
arch=(any)
url="https://github.com/python-poetry/$_pkgname"
license=(MIT)
depends=(python-crashtest
         python-rapidfuzz
         python-typing_extensions)
makedepends=(python-{build,installer,wheel}
             python-poetry-core)
checkdepends=(python-pytest
              python-pytest-mock)
_archive="$_pkgname-$pkgver"
source=("$url/archive/$pkgver/$_archive.tar.gz")
sha256sums=('cb9b60c9559d26a289b0536b134f9efe1b59632f51dc38b20c8a9076b99e0f07')
b2sums=('dcaeff38c2dcb13b3c11200aa97cb2a1c16004558aabf9b44f1ba7ddd5d9c8c7784ea0ba1c50c19b015a6ff0659cb116b8ee926670091e39fd2b1cfd426cb72a')

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
