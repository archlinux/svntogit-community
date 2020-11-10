# Maintainer: Thore Bödecker <foxxx0@archlinux.org>
# Contributor: Sébastien "Seblu" Luttringer <seblu@archlinux.org>

pkgbase='ceph'
pkgname=('ceph' 'ceph-libs' 'ceph-mgr')
_zstdver=1.4.5
pkgver=14.2.8
pkgrel=1
pkgdesc='Distributed, fault-tolerant storage platform delivering object, block, and file system'
arch=('x86_64')
url='https://ceph.com/'
license=('GPL')
makedepends=("zstd=${_zstdver}" 'bc' 'boost' 'boost-libs' 'cmake' 'coffeescript'
             'cpio' 'crypto++' 'cryptsetup' 'cunit' 'curl' 'cython' 'expat'
             'fcgi' 'fontconfig' 'fuse2' 'gcc' 'gcc-libs' 'git' 'glibc' 'gmock'
             'gperf' 'gperftools' 'gptfdisk' 'gtest' 'inetutils' 'java-runtime'
             'jq' 'jre11-openjdk-headless' 'junit' 'keyutils' 'leveldb' 'libaio'
             'libatomic_ops' 'libcap' 'libcap-ng' 'libcroco' 'libcurl-compat'
             'libedit' 'libgudev' 'librabbitmq-c' 'libtool' 'util-linux-libs'
             'libuv' 'libxml2' 'lsb-release' 'lz4' 'ncurses'
             'nss' 'oath-toolkit' 'openssl' 'parted' 'pcre' 'pcre2' 'pkgconf'
             'procps-ng' 'python-astroid' 'python-attrs' 'python-bcrypt'
             'python-cheroot' 'python-cherrypy' 'python-coverage'
             'python-elasticsearch' 'python-flask' 'python-flask-restful'
             'python-google-api-python-client' 'python-google-auth'
             'python-google-auth-httplib2' 'python-grpcio' 'python-isort'
             'python-jinja' 'python-lazy-object-proxy' 'python-mccabe'
             'python-isodate' 'python-defusedxml' 'python-pkgconfig'
             'python-lxml' 'python-xmlsec' 'python-yaml'
             'python-more-itertools' 'python-numpy' 'python-pbr' 'python-pecan'
             'python-pip' 'python-pluggy' 'python-portend' 'python-prettytable'
             'python-prometheus_client' 'python-py' 'python-pycparser'
             'python-pyjwt' 'python-pyopenssl' 'python-pytz' 'python-requests'
             'python-routes' 'python-scikit-learn' 'python-scipy'
             'python-setuptools' 'python-six' 'python-sphinx' 'python-tempora'
             'python-virtualenv' 'python-werkzeug' 'python-wrapt' 'rabbitmq'
             'sed' 'snappy' 'socat' 'systemd' 'systemd-libs' 'valgrind'
             'xfsprogs' 'xmlstarlet' 'xxhash' 'yasm' 'zlib' )
checkdepends=('python-mock' 'python-nose' 'python-pycodestyle' 'python-pylint'
              'python-pytest' 'python-pytest-cov')
options=('emptydirs')
source=("https://download.ceph.com/tarballs/${pkgbase}-${pkgver}.tar.gz"
        'ceph.sysusers'
        'remove-distro-version-detection.patch'
        'disable-empty-readable.sh-test.patch'
        'use-threadsafe-death-tests-objectstore-memstore.patch'
        'use-system-zstd-and-fix-zstd-1.4.0-compatbility.patch'
        'suppress-pylint-warnings.patch'
        'fix-mgr-dashboard-frontend-unittests-dist-stuff.patch'
        "zstd-${_zstdver}.tar.gz::https://github.com/facebook/zstd/archive/v${_zstdver}.tar.gz")
sha512sums=('38b0c6df58579377528c8f8e06d0cbc40f471f6eb2fb4a05b395f6fddbd3f2117674545b2147d8730973b01967ddcd4322a769ba03f9c625417ed35cc39f195a'
            '4354001c1abd9a0c385ba7bd529e3638fb6660b6a88d4e49706d4ac21c81b8e829303a20fb5445730bdac18c4865efb10bc809c1cd56d743c12aa9a52e160049'
            '02c9e8fd3c23fb4c9c4c576ee6d06e8525ca31decfd964fb7231e73c98fe2987a483dda680969752186f0918f47d9af4fb09a4901e5319077f45d870906716da'
            '2234d005df71b3b6013e6b76ad07a5791e3af7efec5f41c78eb1a9c92a22a67f0be9560be59b52534e90bfe251bcf32c33d5d40163f3f8f7e7420691f0f4a222'
            'a74aea7c0b0d1883c874f889c184bd2c766fa578d6ca0cbe5eaada840281bb947b3d80f142b30473058cd2652d2967d241ade6914d6be50e93e91728a31733c8'
            '4345fc2f422c7c1910bfd4068ad39511fa63d8c1e4fc04af416bb0f3869e43327d4a4bfc980d5abf273693a532ac153ed1e4c03e033a127692c1254b99092b8a'
            '4afd5c3b49a839531921e80b1204ef5b496531a31b3de13042bfcbb548d736851ef7698e41bc94a9bed356e7c2cab6bf30bc711796249cf10ee791974033c29b'
            '6265e083e0e8cba481741c7492a47e8144381287c2cbaef220a64bd889d8bac43cb5cc3efb01600cf785d585c950982a908deed10bedf0688c5cd2015e004c1f'
            'b03c497c3e0590c3d384cb856e3024f144b2bfac0d805d80e68deafa612c68237f12a2d657416d476a28059e80936c79f099fc42331464b417593895ea214387')


# -fno-plt causes linker errors (undefined reference to internal methods)
# similar issue: https://bugs.archlinux.org/task/54845
# https://github.com/intel/media-driver/commit/d95d8f7ab7ac94a2e0f4ee6a4b4794898dc2d3b7
# as of today (2019-07-12) the upstream maintainers do not consider this a bug in their code
# (IMHO rightfully so) and thus we strip the option here
CFLAGS="${CFLAGS/-fno-plt/}"
CXXFLAGS="${CXXFLAGS/-fno-plt/}"


prepare() {
  cd "${srcdir}/${pkgbase}-${pkgver}"

  # the src/pybind/mgr/dashboard/run-frontend-unittests.sh helper will incorrectly
  # rebuild the static assets to frontend/dist/ causing failures in run-tox-mgr-dashboard
  # and in the final package
  # with fix-mgr-dashboard-frontend-unittests-dist-stuff.patch we comment out
  # the npm build and i18n commands of this helper and just use the remainder to run the actual tests

  # apply patches from the source array
  local filename
  for filename in "${source[@]}"; do
    if [[ "${filename}" =~ \.patch$ ]]; then
      echo "Applying patch ${filename##*/}"
      patch -p1 -N -i "${srcdir}/${filename##*/}"
    fi
  done

  # suppress deprecation warnings
  sed -i '/#ifndef CEPH_CONFIG_H/i#define BOOST_ALLOW_DEPRECATED_HEADERS' \
    src/common/config.h
  sed -i '/#ifndef CEPH_TYPES_H/i#define BOOST_ALLOW_DEPRECATED_HEADERS' \
    src/include/types.h

  # remove bundled zstd and replace with newer release
  rm -rf src/zstd
  ln -sf "${srcdir}/zstd-${_zstdver}" src/zstd

  # remove tests that require root privileges
  rm src/test/cli/ceph-authtool/cap*.t

  # disable certain pylint test cases (we don't are about them for packaging)
  sed -i 's/,py3-lint//' src/pybind/mgr/dashboard/run-tox.sh


  # this test will try to perform btrfs operations when a btrfs mount
  # is active on the build host, which will fail
  # if mount | grep 'type btrfs' &>/dev/null; then
  #   sed -i '/run-tox-ceph-disk/d' src/test/CMakeLists.txt
  # fi
}

build() {
  cd "${srcdir}/${pkgbase}-${pkgver}"

  mkdir -p build
  cd build

  export PYTHON_INCLUDE_DIR="$(python -c "from sysconfig import get_path; print(get_path('include'))")"

  cmake \
    -DCMAKE_INSTALL_PREFIX=/usr \
    -DCMAKE_INSTALL_SYSCONFDIR=/etc \
    -DCMAKE_INSTALL_SBINDIR=/usr/bin \
    -DCMAKE_INSTALL_LIBDIR=/usr/lib \
    -DCEPH_SYSTEMD_ENV_DIR=/etc/default \
    -DCMAKE_INSTALL_LIBEXECDIR=/usr/lib \
    -DCMAKE_INSTALL_SYSTEMD_SERVICEDIR=/usr/lib/systemd/system \
    -DCMAKE_VERBOSE_MAKEFILE=ON \
    -DCMAKE_BUILD_TYPE=RelWithDebInf \
    -DENABLE_GIT_VERSION=ON \
    -DWITH_PYTHON2=OFF \
    -DWITH_PYTHON3=ON \
    -DMGR_PYTHON_VERSION=3 \
    -DPYTHON_INCLUDE_DIR="${PYTHON_INCLUDE_DIR:?}" \
    -DWITH_BABELTRACE=OFF \
    -DWITH_LTTNG=OFF \
    -DWITH_OPENLDAP=OFF \
    -DWITH_RDMA=OFF \
    -DWITH_OCF=OFF \
    -DWITH_DPDK=OFF \
    -DWITH_SPDK=OFF \
    -DWITH_CEPHFS=ON \
    -DWITH_CEPHFS_JAVA=ON \
    -DWITH_CEPHFS_SHELL=ON \
    -DWITH_FUSE=ON \
    -DWITH_LZ4=ON \
    -DWITH_XFS=ON \
    -DWITH_MGR=ON \
    -DWITH_MGR_DASHBOARD_FRONTEND=ON \
    -DDASHBOARD_FRONTEND_LANGS="ALL" \
    -DWITH_RADOSGW=ON \
    -DWITH_RADOSGW_FCGI_FRONTEND=OFF \
    -DWITH_RADOSGW_BEAST_FRONTEND=ON \
    -DWITH_RADOSGW_BEAST_OPENSSL=ON \
    -DWITH_RADOSGW_AMQP_ENDPOINT=OFF \
    -DWITH_SYSTEMD=ON \
    -DWITH_SYSTEM_BOOST=OFF \
    -DWITH_BOOST_CONTEXT=ON \
    -DWITH_SYSTEM_GTEST=OFF \
    -DWITH_SYSTEM_NPM=OFF \
    -DENABLE_SHARED=ON \
    -DWITH_TESTS=ON \
    ..

  VERBOSE=1 make all
}

check() {
  cd "${srcdir}/${pkgbase}-${pkgver}/build"

  export CTEST_PARALLEL_LEVEL="8"
  VERBOSE=1 make check

  # sometimes processes are not properly terminated...
  for process in ceph-mon ceph-mgr ceph-osd; do
    pkill -9 "${process}" || true
  done
}

package_ceph-libs() {
  depends=('boost-libs' 'curl' 'glibc' 'keyutils' 'util-linux-libs' 'lz4' 'nss'
           'oath-toolkit' 'python' 'snappy' 'systemd-libs')

  cd "${srcdir}/${pkgbase}-${pkgver}/build"

  # main install
  VERBOSE=1 make DESTDIR="${pkgdir}" install

  # remove stuff that goes into the ceph package
  rm -rf "${pkgdir}"/usr/lib/{ceph/mgr,systemd,sysusers.d,tmpfiles.d}
  rm -rf "${pkgdir}/usr/share"
  rm -rf "${pkgdir}/usr/sbin"
  rm -rf "${pkgdir}/usr/bin"
  rm -rf "${pkgdir}/etc"
  rm -rf "${pkgdir}/var"
}

package_ceph() {
  depends=("ceph-libs=${pkgver}-${pkgrel}"
           'boost-libs' 'curl' 'fuse2' 'glibc' 'gperftools' 'java-runtime'
           'keyutils' 'leveldb' 'libaio' 'util-linux-libs' 'lsb-release' 'ncurses'
           'nss' 'oath-toolkit' 'python' 'python-bcrypt' 'python-setuptools'
           'python-cmd2' 'snappy' 'systemd-libs' 'xfsprogs')

  cd "${srcdir}/${pkgbase}-${pkgver}/build"

  # main install
  VERBOSE=1 make DESTDIR="${pkgdir}" install

  # fix sbin dir (cmake opt seems to have no effect)
  mv "${pkgdir}"/usr/sbin/* "${pkgdir}/usr/bin/"
  rm -rf "${pkgdir}/usr/sbin"

  # remove stuff that is in the ceph-libs package
  find "${pkgdir}/usr/lib" -maxdepth 1 -type f -delete
  find "${pkgdir}/usr/lib" -maxdepth 1 -type l -delete
  find "${pkgdir}/usr/lib/ceph" -maxdepth 1 -type f -delete
  find "${pkgdir}/usr/lib/ceph" -maxdepth 1 -type l -delete
  rm -rf "${pkgdir}"/usr/lib/{ceph/{compressor,crypto,erasure-code},rados-classes}
  rm -rf "${pkgdir}"/usr/lib/python*
  rm -rf "${pkgdir}/usr/include"

  # remove stuff that is in the ceph-mgr package
  rm -rf "${pkgdir}"/usr/{bin/ceph-mgr,share/ceph/mgr,lib/systemd/system/ceph-mgr*}

  # remove _test_ binaries from the package, not needed
  find "${pkgdir}/usr/bin" -maxdepth 1 -type f -iname 'ceph_test_*' -delete

  # install tmpfiles.d and sysusers.d stuff
  install -Dm644 "${srcdir}/${pkgbase}-${pkgver}/systemd/ceph.tmpfiles.d" \
    "${pkgdir}/usr/lib/tmpfiles.d/${pkgbase}.conf"
  install -Dm644 "${srcdir}/ceph.sysusers" \
    "${pkgdir}/usr/lib/sysusers.d/${pkgbase}.conf"

  # remove debian init script
  rm -rf "${pkgdir}/etc/init.d"

  # remove drop.ceph.com ssh stuff
  rm -f "${pkgdir}"/usr/share/ceph/id_rsa_drop.ceph.com
  rm -f "${pkgdir}"/usr/share/ceph/id_rsa_drop.ceph.com.pub
  rm -f "${pkgdir}"/usr/share/ceph/known_hosts_drop.ceph.com

  # fix bash completions path
  install -d -m 755 "${pkgdir}/usr/share/bash-completion"
  mv "${pkgdir}"/{etc/bash_completion.d,usr/share/bash-completion/completions}

  # fix EnvironmentFile location in systemd service files
  sed -i 's|/etc/sysconfig/|/etc/conf.d/|g' "${pkgdir}"/usr/lib/systemd/system/*.service

  # prepare some paths and set correct permissions
  install -D -d -m750 -o   0 -g 340 "${pkgdir}/etc/ceph"
  install -D -d -m750 -o 340 -g 340 "${pkgdir}/var/log/ceph"
  install -D -d -m750 -o 340 -g 340 "${pkgdir}/var/lib/ceph"
  install -D -d -m750 -o 340 -g 340 "${pkgdir}/var/lib/ceph/bootstrap-mds"
  install -D -d -m750 -o 340 -g 340 "${pkgdir}/var/lib/ceph/bootstrap-osd"
  install -D -d -m750 -o 340 -g 340 "${pkgdir}/var/lib/ceph/bootstrap-rgw"
  install -D -d -m750 -o 340 -g 340 "${pkgdir}/var/lib/ceph/mon"
  install -D -d -m750 -o 340 -g 340 "${pkgdir}/var/lib/ceph/osd"
}

package_ceph-mgr() {
  depends=("ceph=${pkgver}-${pkgrel}" "ceph-libs=${pkgver}-${pkgrel}"
           'bash' 'boost-libs' 'coffeescript' 'curl' 'gperftools' 'nodejs' 'nss'
           'python' 'python-cherrypy' 'python-flask-restful' 'python-pecan'
           'python-pyjwt' 'python-routes' 'python-requests' 'python-pyopenssl'
           'python-prettytable' 'python-yaml')
  optdepends=('python-influxdb: influx module'
              'python-kubernetes: rook module'
              'python-prometheus_client: prometheus module'
              'python-remoto: ssh module')
  conflicts=('ceph<14.2.1-1')

  cd "${srcdir}/${pkgbase}-${pkgver}/build"

  # main install
  VERBOSE=1 make DESTDIR="${pkgdir}" install

  # fix sbin dir (cmake opt seems to have no effect)
  mv "${pkgdir}"/usr/sbin/* "${pkgdir}/usr/bin/"
  rm -rf "${pkgdir}/usr/sbin"

  # remove everything except mgr related stuff, rest is in ceph/ceph-libs
  rm -rf "${pkgdir}"/usr/lib/{ceph/{compressor,crypto,erasure-code},rados-classes}
  rm -rf "${pkgdir}/usr/include"
  find "${pkgdir}/usr/bin" -maxdepth 1 -type f -not -name 'ceph-mgr' -delete
  find "${pkgdir}"/usr/lib/systemd/system -maxdepth 1 -type f -not -iname 'ceph-mgr*' -delete
  find "${pkgdir}"/usr/lib -maxdepth 1 -type f -delete
  find "${pkgdir}"/usr/lib -maxdepth 1 -type l -delete
  rm -rf "${pkgdir}"/etc
  rm -rf "${pkgdir}"/var
  rm -rf "${pkgdir}"/usr/lib/{ceph,sysusers.d,tmpfiles.d}
  rm -rf "${pkgdir}"/usr/lib/python*
  rm -rf "${pkgdir}"/usr/share/{bash-completion,doc,java,man}

  # remove debian init script
  rm -rf "${pkgdir}/etc/init.d"

  # remove drop.ceph.com ssh stuff
  rm -f "${pkgdir}"/usr/share/ceph/id_rsa_drop.ceph.com
  rm -f "${pkgdir}"/usr/share/ceph/id_rsa_drop.ceph.com.pub
  rm -f "${pkgdir}"/usr/share/ceph/known_hosts_drop.ceph.com

  # fix EnvironmentFile location in systemd service files
  sed -i 's|/etc/sysconfig/|/etc/conf.d/|g' "${pkgdir}"/usr/lib/systemd/system/*.service

  # prepare some paths and set correct permissions
  install -D -d -m750 -o 340 -g 340 "${pkgdir}/var/lib/ceph/mgr"
}

# vim:set ts=2 sw=2 et:
