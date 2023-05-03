# Maintainer: Sven-Hendrik Haase <svenstaro@archlinux.org>
pkgname=python-absl
pkgver=1.4.0
pkgrel=3
pkgdesc="Abseil Python Common Libraries"
arch=('any')
url='https://github.com/abseil/abseil-py'
provides=('absl-py')
conflicts=('absl-py')
replaces=('absl-py')
license=('APACHE')
makedepends=(python-{build,installer,wheel} python-setuptools)
source=("https://pypi.io/packages/source/a/absl-py/absl-py-$pkgver.tar.gz")
sha512sums=('ebdd8c14308862112367118170f0309335e4b633999d1a02ee9abf1b8be33cb9d8cde33a4980e106b240ecb07766c1c78fd981305ffcc0dee252deaf68a2e47a')

build() {
  cd "$srcdir/absl-py-$pkgver"
  python -m build --wheel --no-isolation
}

package() {
  cd "$srcdir/absl-py-$pkgver"
  python -m installer --destdir="$pkgdir" dist/*.whl
}

# vim:set ts=2 sw=2 et:
