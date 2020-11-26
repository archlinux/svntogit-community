# Maintainer: Kyle Keen <keenerd@gmail.com>
# Contributor: Philipp A. <flying-sheep@web.de>
_name=testpath
pkgname=python-testpath
pkgver=0.4.4
pkgrel=3
pkgdesc='Test utilities for code working with files and commands'
arch=('any')
url="https://pypi.python.org/pypi/testpath"
license=('MIT')
depends=('python')
#makedepends=('python-pip')
_wheel="$_name-$pkgver-py2.py3-none-any.whl"
# both sources because the WHL doesn't come with a license
source=("$pkgname-$pkgver.tgz::https://github.com/jupyter/testpath/archive/$pkgver.tar.gz"
        "https://files.pythonhosted.org/packages/py2.py3/t/$_name/$_wheel")
#noextract=("$_wheel")
md5sums=('4d7795541fccebd2be9818aead36caf1'
         '5e03fa02495b35f9c33a3303ebe10349')

prepare() {
  cd "$srcdir"
  rm testpath/cli*.exe
  sed -i '/cli-32.exe/d' testpath-$pkgver.dist-info/RECORD
  sed -i '/cli-64.exe/d' testpath-$pkgver.dist-info/RECORD
  sed -i 's/shutil.copy(src, dst)/return/' testpath/commands.py
}

package() {
  #pip install --compile --no-deps --root="$pkgdir" "$_wheel"
  # not using pip here because it installs windows junk

  cd "$srcdir/testpath"
  for _i in ./*; do
    install -Dm644 $_i "$pkgdir/usr/lib/python3.9/site-packages/testpath/$_i"
  done

  _dist="testpath-$pkgver.dist-info"
  cd "$srcdir/$_dist"
  for _i in ./*; do
    install -Dm644 $_i "$pkgdir/usr/lib/python3.9/site-packages/$_dist/$_i"
  done

  cd "$srcdir/testpath-$pkgver"
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
